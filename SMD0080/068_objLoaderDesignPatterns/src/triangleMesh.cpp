#include <GL/gl.h>
#include <triangleMesh.h>

#include "renderer.h"

// --------------------------------------------------------------------------
Color TriangleMesh::edgeColor = Color::BLUE;
Color TriangleMesh::vertexColor = Color::RED;
// --------------------------------------------------------------------------
Box3 getBoundingBox( const Scene& s )
{
	Box3 box;
	for( const auto& m : s )
	{
		box.add( m.getBoundingBox().min );
		box.add( m.getBoundingBox().max );
	}

	return box;
}
// --------------------------------------------------------------------------
TriangleMesh::TriangleMesh()
	:
		vertices(),
		material( Material::MT_GOLD ),
		drawModes( TriangleMesh::DRAW_TRIANGLES ),
		aabb(),
		hasNormals(false)
{
}
// --------------------------------------------------------------------------
TriangleMesh::~TriangleMesh()
{
}
// --------------------------------------------------------------------------
TriangleMesh::TriangleMesh(const TriangleMesh& rhs)
	:
		vertices( rhs.vertices ),
		material( rhs.material ),
		drawModes( rhs.drawModes ),
		aabb(rhs.aabb),
		hasNormals( rhs.hasNormals )
{

}
// --------------------------------------------------------------------------
TriangleMesh& TriangleMesh::operator=(const TriangleMesh& rhs)
{
	if( this != & rhs )
	{
		vertices  =  rhs.vertices;
		material  =  rhs.material;
		drawModes =  rhs.drawModes;
		aabb = rhs.aabb;
		hasNormals = rhs.hasNormals;
	}

	return *this;
}
// --------------------------------------------------------------------------
void TriangleMesh::setMaterial( const Material& m )
{
	material = m;
}
// --------------------------------------------------------------------------
void TriangleMesh::setHasNormals( bool b )
{
	hasNormals = b;
}
// --------------------------------------------------------------------------
bool TriangleMesh::getHasNormals() const
{
	return hasNormals;
}
// --------------------------------------------------------------------------
Vec3 TriangleMesh::triangleNormal( const Vertex& v0, const Vertex& v1, const Vertex& v2 )
{
	return TriangleMesh::triangleNormal( v0.position, v1.position, v2.position );
}
// --------------------------------------------------------------------------
Vec3 TriangleMesh::triangleNormal( const Vec3& v0, const Vec3& v1, const Vec3& v2 )
{
	return (v1-v0).cross(v2-v0).normalize();
}
// --------------------------------------------------------------------------
void TriangleMesh::setDrawMode( unsigned char dm )
{
	drawModes = dm;
}
// --------------------------------------------------------------------------
void TriangleMesh::clear()
{
	vertices.clear();
}
// --------------------------------------------------------------------------
const VertexArray& TriangleMesh::getVertices() const
{
	return vertices;
}
// --------------------------------------------------------------------------
void TriangleMesh::addVertex( float x, float y, float z )
{
	vertices.push_back( Vertex( Vec3(x,y,z)) );
}
// --------------------------------------------------------------------------
const Box3& TriangleMesh::getBoundingBox() const
{
	return aabb;
}
// --------------------------------------------------------------------------
void TriangleMesh::addVertex( const Vertex& v )
{
	vertices.push_back( v );
	aabb.add( v.position );
}
// --------------------------------------------------------------------------

// --------------------------------------------------------------------------
void TriangleMesh::draw(void) const
{
	if( drawModes & TriangleMesh::DRAW_TRIANGLES )
	{
		glEnable(GL_LIGHTING);
		glDisable( GL_COLOR_MATERIAL );
		{
			Renderer::setupMaterial(material);
			_drawTriangles();
		}
		glEnable( GL_COLOR_MATERIAL );
	}


	glDisable(GL_LIGHTING);
	if( drawModes & TriangleMesh::DRAW_EDGES )
	{
		const Color& c = edgeColor;
		glColor4f( c.r, c.g, c.b, c.a );

		_drawEdges();
	}

	if( drawModes & TriangleMesh::DRAW_VERTICES )
	{
		const Color& c = vertexColor;
		glColor4f( c.r, c.g, c.b, c.a );

		_drawVertices();
	}

	if( drawModes & TriangleMesh::DRAW_AABB )
	{
		glColor3f( 1,0,0 );

		// TODO pintar bounding box
		glBegin(GL_LINE_LOOP);

		glEnd();
	}
}
// --------------------------------------------------------------------------
