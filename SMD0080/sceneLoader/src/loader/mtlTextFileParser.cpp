#include <loader/mtlTextFileParser.h>

#define ILUT_USE_OPENGL
#include <IL/ilut.h>

struct NewMaterialCommand : public LineBasedParsingCommand
{
	NewMaterialCommand()
		: LineBasedParsingCommand("newmtl ")
	{}

	bool processLine(TextFileParser& tfp, const String& line) override
	{
		MaterialTextFileParser& mat = dynamic_cast<MaterialTextFileParser&>(tfp);
		MaterialVector& materials = mat.getOwner().getContext().materials;

		// cria o novo material
		materials.push_back( Material() );
		materials.back().name = line;

		return false;
	}
};
struct ShininessCommand : public LineBasedParsingCommand
{
	ShininessCommand()
		: LineBasedParsingCommand("Ns ")
	{}

	bool processLine(TextFileParser& tfp, const String& line) override
	{
		MaterialTextFileParser& mat = dynamic_cast<MaterialTextFileParser&>(tfp);
		MaterialVector& materials = mat.getOwner().getContext().materials;
		if( materials.empty() ) return true;

		// NOTA: causa bugs em certos modelos
		const float ns = std::atof( line.c_str() )/ 1000.0f;
		//materials.back().ns = ns;
		return false;
	}
};
struct AmbientColorCommand : public LineBasedParsingCommand
{
	AmbientColorCommand()
		: LineBasedParsingCommand("Ka ")
	{}

	bool processLine(TextFileParser& tfp, const String& line) override
	{
		MaterialTextFileParser& mat = dynamic_cast<MaterialTextFileParser&>(tfp);
		MaterialVector& materials = mat.getOwner().getContext().materials;

		if( materials.empty() ) return true;

		Color cor;
		StringInputStream iss(line);

		iss >> cor.r >> cor.g >> cor.b;

		materials.back().ka = cor;
		return false;
	}
};
struct DiffuseColorCommand : public LineBasedParsingCommand
{
	DiffuseColorCommand()
		: LineBasedParsingCommand("Kd ")
	{}

	bool processLine(TextFileParser& tfp, const String& line) override
	{
		MaterialTextFileParser& mat = dynamic_cast<MaterialTextFileParser&>(tfp);
		MaterialVector& materials = mat.getOwner().getContext().materials;

		if( materials.empty() )
			return true;

		Color cor;
		StringInputStream iss(line);

		iss >> cor.r >> cor.g >> cor.b;
		materials.back().kd = cor;
		return false;
	}
};
struct SpecularColorCommand : public LineBasedParsingCommand
{
	SpecularColorCommand()
		: LineBasedParsingCommand("Ks ")
	{}

	bool processLine(TextFileParser& tfp, const String& line) override
	{
		MaterialTextFileParser& mat = dynamic_cast<MaterialTextFileParser&>(tfp);
		MaterialVector& materials = mat.getOwner().getContext().materials;

		if( materials.empty() ) return true;

		Color cor;
		StringInputStream iss(line);

		iss >> cor.r >> cor.g >> cor.b;
		materials.back().ks = cor;
		return false;
	}
};
//
struct DiffuseTextureCommand : public LineBasedParsingCommand
{
	DiffuseTextureCommand()
		: LineBasedParsingCommand("map_Kd ")
	{}

	bool processLine(TextFileParser& tfp, const String& line) override
	{
		MaterialTextFileParser& mtlParser = dynamic_cast<MaterialTextFileParser&>(tfp);
		MaterialVector& materials = mtlParser.getOwner().getContext().materials;

		if( materials.empty() ) return true;

		// carrega a textura
		String filename = mtlParser.getBaseDir() + line;
		Material& mat = materials.back();

		if( ilLoadImage( filename.c_str() ) )
		{
			glEnable(GL_TEXTURE_2D);

			mat.textureId = ilutGLBindTexImage();

			glDisable(GL_TEXTURE_2D);
		}

		return false;
	}
};

static NewMaterialCommand newmtlCmd;
static ShininessCommand nsCmd;
static AmbientColorCommand kaCmd;
static DiffuseColorCommand kdCmd;
static SpecularColorCommand ksCmd;

static DiffuseTextureCommand map_KdCmd;

// --------------------------------------------------------------------------
MaterialTextFileParser::MaterialTextFileParser (const String& filename, ObjTextFileParser& owner)
	: TextFileParser(filename), _owner(owner)
{
	lineCommands.push_back( &newmtlCmd );

	lineCommands.push_back( &nsCmd );

	lineCommands.push_back( &kaCmd );
	lineCommands.push_back( &kdCmd );
	lineCommands.push_back( &ksCmd );

	lineCommands.push_back( &map_KdCmd );
}
// --------------------------------------------------------------------------
MaterialTextFileParser::~MaterialTextFileParser ()
{
}
// --------------------------------------------------------------------------
ObjTextFileParser& MaterialTextFileParser::getOwner()
{
	return _owner;
}
// --------------------------------------------------------------------------
