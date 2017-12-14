#include <loader/objTextFileParser.h>
#include <loader/mtlTextFileParser.h>

// 21:40
// --------------------------------------------------------------------------
struct NewObjCommand : public LineBasedParsingCommand
{
	NewObjCommand()
		: LineBasedParsingCommand("o ")
	{}

	bool processLine(TextFileParser& tfp, const String& line) override
	{
		ObjTextFileParser& obj = dynamic_cast<ObjTextFileParser&>(tfp);

		obj.getContext().scene->push_back( IndexedTriangleMesh() );
		return false;
	}
};
// --------------------------------------------------------------------------
struct NewVertexCommand : public LineBasedParsingCommand
{
	NewVertexCommand()
		: LineBasedParsingCommand("v ")
	{}

	bool processLine(TextFileParser& tfp, const String& line) override
	{
		ObjTextFileParser& obj = dynamic_cast<ObjTextFileParser&>(tfp);

		StringInputStream sis( line );
		Vec3 v;

		sis >> v.x >> v.y  >> v.z;
		obj.getContext().vertices.push_back( v );
		return false;
	}
};
// --------------------------------------------------------------------------
struct NewVertexNormalCommand : public LineBasedParsingCommand
{
	NewVertexNormalCommand()
		: LineBasedParsingCommand("vn ")
	{}

	bool processLine(TextFileParser& tfp, const String& line) override
	{
		ObjTextFileParser& obj = dynamic_cast<ObjTextFileParser&>(tfp);

		StringInputStream sis( line );
		Vec3 v;

		sis >> v.x >> v.y  >> v.z;
		obj.getContext().normals.push_back( v );
		return false;
	}
};
// --------------------------------------------------------------------------
struct NewVertexTextureCoordinateCommand : public LineBasedParsingCommand
{
	NewVertexTextureCoordinateCommand()
		: LineBasedParsingCommand("vt ")
	{}

	bool processLine(TextFileParser& tfp, const String& line) override
	{
		ObjTextFileParser& obj = dynamic_cast<ObjTextFileParser&>(tfp);

		StringInputStream sis( line );
		Vec2 v;

		sis >> v.x >> v.y;
		obj.getContext().tcs.push_back( v );
		return false;
	}
};
// --------------------------------------------------------------------------
struct LoadMaterialsCommand : public LineBasedParsingCommand
{
	LoadMaterialsCommand()
		: LineBasedParsingCommand("mtllib ")
	{}

	bool processLine(TextFileParser& tfp, const String& line) override
	{
		ObjTextFileParser& obj = dynamic_cast<ObjTextFileParser&>(tfp);

		String mtlFilename = obj.getBaseDir() + line;
		return MaterialTextFileParser( mtlFilename, obj ).parse();
	}
};
// --------------------------------------------------------------------------
struct UseMaterialCommand : public LineBasedParsingCommand
{
	UseMaterialCommand()
		: LineBasedParsingCommand("usemtl ")
	{}

	bool processLine(TextFileParser& tfp, const String& line) override
	{
		ObjTextFileParser& obj = dynamic_cast<ObjTextFileParser&>(tfp);

		// AJUSTE: evita adicionar material na cena vazia
		if( obj.getContext().scene->empty() )
			obj.getContext().scene->push_back( IndexedTriangleMesh() );

		for( auto& m : obj.getContext().materials )
		{
			if( (m.name == line) &&  !obj.getContext().scene->empty() )
			{
				obj.getContext().scene->back().setMaterial(m);
				break;
			}
		}
		return false;
	}
};
// --------------------------------------------------------------------------
struct NewGroupCommand : public LineBasedParsingCommand
{
	NewGroupCommand()
		: LineBasedParsingCommand("g ")
	{}

	bool processLine(TextFileParser& tfp, const String& line) override
	{
		ObjTextFileParser& obj = dynamic_cast<ObjTextFileParser&>(tfp);

		if( obj.getContext().scene->empty() )
			obj.getContext().scene->push_back( IndexedTriangleMesh() );
		return false;
	}
};
// --------------------------------------------------------------------------
struct NewFaceCommand : public LineBasedParsingCommand
{
	NewFaceCommand()
		: LineBasedParsingCommand("f ")
	{}

	bool processLine(TextFileParser& tfp, const String& line) override
	{
		ObjTextFileParser& obj = dynamic_cast<ObjTextFileParser&>(tfp);

		// evita parsing de linhas muito pequenas
		if( line.length() < 5 )
		{
			std::cerr << "[ERROR] line lacks data" << std::endl;
			return true;
		}

		// evita adicionar faces numa cena vazia
		if( obj.getContext().scene->empty() )
			obj.getContext().scene->push_back( IndexedTriangleMesh() );

		IndexedTriangleMesh& mesh = obj.getContext().scene->back();

		return  ( mesh.getTriangleCount() == 0 ) ?
				_parseFirstFace(obj.getContext(), line) :
				_parseFace(obj.getContext(), line);
	}

protected:

	FaceLayout classifyFace( const String& line)
	{
		size_t pos = line.find_first_of('/');

		// apenas vértices, pois não usa o separador
		if( pos == String::npos )
			return FACE_POS;

		if( pos >= (line.length()-1) )
			return FACE_UNSUPPORTED;

		// duas barras seguidas indicam posição e normal
		char c = line[pos+1];
		if( c == '/')
			return FACE_POS_NORMAL;

		// discernir entre FACE_POS_TEX e FACE_FULL
		if( c >='0' && c <= '9' )
		{
			// uma segunda barra aparece antes do próximo espaço
			size_t w = line.find_first_of(' ');
			size_t b = line.find_first_of( '/', pos+1);

			if( b < w )
			{
				return FACE_FULL;
			}
			else
				return FACE_POS_TEX;
		}

		return FACE_UNSUPPORTED;
	}

	bool _parseFirstFace(ObjTextFileContext& ctx, const String& line )
	{
		ctx.fl = classifyFace(line);
		if( ctx.fl == FACE_UNSUPPORTED)
		{
			std::cerr << "[ERROR] unsupported face layout @ "<< line << std::endl;
			return true;
		}

		IndexedTriangleMesh& mesh = ctx.scene->back();
		mesh.setHasNormals( ctx.fl == FACE_FULL || ctx.fl == FACE_POS_NORMAL );

		return _parseFace( ctx, line );
	}

	bool _parseFace(ObjTextFileContext& ctx, const String& line )
	{
		IndexedTriangleMesh& mesh = ctx.scene->back();
		switch( ctx.fl )
		{
		case FACE_POS:
		{
			StringInputStream sis( line );
			std::vector< unsigned int > faceIndices;

			while( !sis.eof() )
			{
				unsigned int k;
				sis >> k;

				faceIndices.push_back( k - 1 );
			}

			// Cada triângulo daquela face, que é convexa!
			// Ex: "f 1 2 3 4" produz duas faces, uma formada pelos vértices (1 2 3) e outra pelos vértices (1 3 4)
			for( unsigned int i=1 ; i <(faceIndices.size()-1) ; i++ )
			{
				//
				unsigned int baseIndex = mesh.getVertexCount();

				// adiciona os 3 vértices
				mesh.addVertex( ctx.vertices[ faceIndices[0  ] ] );
				mesh.addVertex( ctx.vertices[ faceIndices[i  ] ] );
				mesh.addVertex( ctx.vertices[ faceIndices[i+1] ] );


				// adiciona a face, porém de forma burra. deixaremos a compactação para depois
				mesh.addTriangle( baseIndex, baseIndex+1, baseIndex+2  );
			}
			return false;
			break;
		}
		case FACE_FULL:
		{
			struct index
			{
				unsigned int v, t, n;
			};
			std::vector<index> fullIndices;
			Vertex v;

			StringInputStream sis( line );
			while( !sis.eof() )
			{
				index vtn;
				char _bar;

				sis >> vtn.v >> _bar >> vtn.t >> _bar >> vtn.n;

				vtn.v -= 1, vtn.t -= 1, vtn.n -= 1;
				fullIndices.push_back(  vtn );
			}

			for( unsigned int i=1 ; i <(fullIndices.size()-1) ; i++ )
			{
				//
				unsigned int baseIndex = mesh.getVertexCount();

				// adiciona os 3 vértices
				mesh.addVertex( Vertex( ctx.vertices[ fullIndices[0  ].v], ctx.normals[ fullIndices[0  ].n], ctx.tcs[ fullIndices[0  ].t] ) );
				mesh.addVertex( Vertex( ctx.vertices[ fullIndices[i  ].v], ctx.normals[ fullIndices[i  ].n], ctx.tcs[ fullIndices[i  ].t] ) );
				mesh.addVertex( Vertex( ctx.vertices[ fullIndices[i+1].v], ctx.normals[ fullIndices[i+1].n], ctx.tcs[ fullIndices[i+1].t] ) );

				// adiciona a face, porém de forma burra. deixaremos a compactação para depois
				mesh.addTriangle( baseIndex, baseIndex+1, baseIndex+2  );
			}
			return false;
			break;
		}
		// TODO implementar outros tipos de face!
		case FACE_POS_NORMAL:
		{
			struct index
			{
				unsigned int v,n;
			};
			std::vector<index> fullIndices;
			Vertex v;

			StringInputStream sis( line );
			while( !sis.eof() )
			{
				index vtn;
				char _bar;

				sis >> vtn.v >> _bar >> _bar >> vtn.n;

				vtn.v -= 1, vtn.n -= 1;
				fullIndices.push_back(  vtn );
			}

			for( unsigned int i=1 ; i <(fullIndices.size()-1) ; i++ )
			{
				//
				unsigned int baseIndex = mesh.getVertexCount();

				// adiciona os 3 vértices
				mesh.addVertex( Vertex( ctx.vertices[ fullIndices[0  ].v], ctx.normals[ fullIndices[0  ].n] ) );
				mesh.addVertex( Vertex( ctx.vertices[ fullIndices[i  ].v], ctx.normals[ fullIndices[i  ].n] ) );
				mesh.addVertex( Vertex( ctx.vertices[ fullIndices[i+1].v], ctx.normals[ fullIndices[i+1].n] ) );

				// adiciona a face, porém de forma burra. deixaremos a compactação para depois
				mesh.addTriangle( baseIndex, baseIndex+1, baseIndex+2  );
			}
			return false;
		}
		case FACE_POS_TEX:
		case FACE_UNSUPPORTED:
		default:
			return true;
		}
	}


};
// --------------------------------------------------------------------------
// ObjTextFileContext
// --------------------------------------------------------------------------
ObjTextFileContext::ObjTextFileContext()
	: scene(nullptr),
	  vertices(),
	  tcs(),
	  normals(),
	  materials(),
	  fl(FACE_UNSUPPORTED)
{

}
// --------------------------------------------------------------------------
// classe ObjFileParser
// --------------------------------------------------------------------------
static NewObjCommand oCmd;
static NewVertexCommand vCmd;
static NewVertexNormalCommand vnCmd;
static NewVertexTextureCoordinateCommand vtCmd;

static LoadMaterialsCommand mtllibCmd;
static UseMaterialCommand usemtlCmd;

static NewFaceCommand fCmd;

// --------------------------------------------------------------------------
ObjTextFileParser::ObjTextFileParser (const String& filename)
	: TextFileParser(filename),
	  _context()
{
	lineCommands.push_back( &oCmd );
	lineCommands.push_back( &vCmd );
	lineCommands.push_back( &vnCmd );
	lineCommands.push_back( &vtCmd );

	lineCommands.push_back( &mtllibCmd);
	lineCommands.push_back( &usemtlCmd );

	lineCommands.push_back( &fCmd );
}
// --------------------------------------------------------------------------
ObjTextFileParser::~ObjTextFileParser ()
{

}
// --------------------------------------------------------------------------
Scene* ObjTextFileParser::parseScene()
{
	if( parse() )
		return nullptr;

	std::cout <<  _context.scene << std::endl;
	return _context.scene;
}
// --------------------------------------------------------------------------
bool ObjTextFileParser::parse()
{
	// reseta o contexto
	_context.vertices.clear();
	_context.tcs.clear();
	_context.normals.clear();
	_context.materials.clear();

	// cria uma cena para trabalho
	_context.scene = new Scene();

	if( TextFileParser::parse() )
	{
		delete _context.scene;
		_context.scene = nullptr;
		return true;

	}

	// sem erro
	return false;
}
// --------------------------------------------------------------------------
ObjTextFileContext& ObjTextFileParser::getContext()
{
	return _context;
}
// --------------------------------------------------------------------------


