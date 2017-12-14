#include <GL/gl.h>
#include <indexedMesh.h>

IndexedTriangleMesh::IndexedTriangleMesh()
: TriangleMesh(), indices()
{
}

IndexedTriangleMesh::~IndexedTriangleMesh()
{
}

IndexedTriangleMesh::IndexedTriangleMesh(const IndexedTriangleMesh& rhs)
: TriangleMesh(rhs), indices(rhs.indices)
{
}

IndexedTriangleMesh& IndexedTriangleMesh::operator=(const IndexedTriangleMesh& rhs)
{
	if(this != &rhs)
	{
		TriangleMesh::operator=(rhs);
		indices = rhs.indices;
	}

	return *this;
}

void IndexedTriangleMesh::clear()
{
	TriangleMesh::clear();
	indices.clear();
}

void IndexedTriangleMesh::addTriangle(unsigned int a, unsigned int b, unsigned int c)
{
	indices.push_back(a);
	indices.push_back(b);
	indices.push_back(c);
}

void IndexedTriangleMesh::_drawTriangles(void) const
{
	if(material.hasTexture())
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, material.textureId);
	}

	glBegin(GL_TRIANGLES);
		for(size_t t = 0; (t + 2) < indices.size(); t += 3)
		{
			const unsigned int i0 = indices[t + 0];
			const unsigned int i1 = indices[t + 1];
			const unsigned int i2 = indices[t + 2];

			if(hasNormals)
			{
				glTexCoord2fv(&vertices[i0].texture.x);
				glNormal3fv(&vertices[i0].normal.x);
				glVertex3fv(&vertices[i0].position.x);

				glTexCoord2fv(&vertices[i1].texture.x);
				glNormal3fv(&vertices[i1].normal.x);
				glVertex3fv(&vertices[i1].position.x);

				glTexCoord2fv(&vertices[i2].texture.x);
				glNormal3fv(&vertices[i2].normal.x);
				glVertex3fv(&vertices[i2].position.x);
			}
			else
			{
				Vec3 n = TriangleMesh::triangleNormal(vertices[i0],vertices[i1],vertices[i2]);
				glNormal3fv(&n.x);

				glTexCoord2fv(&vertices[i0].texture.x);
				glVertex3fv(&vertices[i0].position.x);

				glTexCoord2fv(&vertices[i1].texture.x);
				glVertex3fv(&vertices[i1].position.x);

				glTexCoord2fv(&vertices[i2].texture.x);
				glVertex3fv(&vertices[i2].position.x);
			}
		}
	glEnd();

	glDisable(GL_TEXTURE_2D);
}

void IndexedTriangleMesh::_drawEdges(void) const
{
	glBegin(GL_LINES);
		for(size_t t = 0; (t + 2) < indices.size(); t += 3)
		{
			const unsigned int i0 = indices[t+0];
			const unsigned int i1 = indices[t+1];
			const unsigned int i2 = indices[t+2];

			glVertex3fv(&vertices[i0].position.x);
			glVertex3fv(&vertices[i1].position.x);

			glVertex3fv(&vertices[i1].position.x);
			glVertex3fv(&vertices[i2].position.x);

			glVertex3fv(&vertices[i2].position.x);
			glVertex3fv(&vertices[i0].position.x);
		}
	glEnd();
}

void IndexedTriangleMesh::_drawVertices(void) const
{
	glBegin(GL_POINTS);
		for(const auto& v : vertices)
		{
			glVertex3fv(&v.position.x);
		}
	glEnd();
}

unsigned int IndexedTriangleMesh::getTriangleCount(void) const
{
	return indices.size() / 3;
}

unsigned int IndexedTriangleMesh::getVertexCount(void) const
{
	return vertices.size();
}
