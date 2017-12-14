#include <GL/gl.h>
#include <triangleMesh.h>

// --------------------------------------------------------------------------
RawTriangleMesh::RawTriangleMesh()
	: TriangleMesh()
{
}
// --------------------------------------------------------------------------
RawTriangleMesh::~RawTriangleMesh()
{
}
// --------------------------------------------------------------------------
void RawTriangleMesh::_drawTriangles(void) const
{
	glBegin( GL_TRIANGLES );
		for( size_t i=0; (i+2)< vertices.size() ; i+=3 )
		{
			const Vec3& p0 = vertices[i+0].position;
			const Vec3& p1 = vertices[i+1].position;
			const Vec3& p2 = vertices[i+2].position;

			if( hasNormals )
			{
				const Vec3& n0 = vertices[i+0].normal;
				const Vec3& n1 = vertices[i+1].normal;
				const Vec3& n2 = vertices[i+2].normal;

				glNormal3fv( &n0.x);
				glVertex3fv( &p0.x );

				glNormal3fv( &n1.x);
				glVertex3fv( &p1.x );


				glNormal3fv( &n2.x);
				glVertex3fv( &p2.x );
			}else
			{
				Vec3 n = TriangleMesh::triangleNormal(p0,p1,p2);
				glNormal3fv( &n.x);

				glVertex3fv( &p0.x );
				glVertex3fv( &p1.x );
				glVertex3fv( &p2.x );
			}
		}
	glEnd();
}
// --------------------------------------------------------------------------
void RawTriangleMesh::_drawEdges(void) const
{
	// NOTA: line loops não são portáveis
	glBegin( GL_LINES );
		for( size_t i=0; (i+2)< vertices.size() ; i+=3 )
		{
			const Vec3& p0 = vertices[i+0].position;
			const Vec3& p1 = vertices[i+1].position;
			const Vec3& p2 = vertices[i+2].position;

			glVertex3fv( &p0.x );
			glVertex3fv( &p1.x );

			glVertex3fv( &p1.x );
			glVertex3fv( &p2.x );

			glVertex3fv( &p2.x );
			glVertex3fv( &p0.x );
		}
	glEnd();
}
// --------------------------------------------------------------------------
void RawTriangleMesh::_drawVertices(void) const
{
	glBegin( GL_POINTS );
		iterateVertices();
	glEnd();
}
// --------------------------------------------------------------------------
void RawTriangleMesh::iterateVertices(void) const
{
	for( const auto& v : vertices )
	{
		glVertex3fv( &v.position.x );
	}
}
// --------------------------------------------------------------------------
unsigned int RawTriangleMesh::getTriangleCount(void) const
{
	return vertices.size()/3;
}
// --------------------------------------------------------------------------
unsigned int RawTriangleMesh::getVertexCount(void) const
{
	return vertices.size();
}
// --------------------------------------------------------------------------
