#ifndef TRIANGLEMESH_CLASS_H
#define TRIANGLEMESH_CLASS_H

#include <material.h>
#include "box3.h"
#include "meshVertex.h"

typedef std::vector<Vertex>        VertexArray;
typedef std::vector<unsigned int>  IndexArray;

enum FaceLayout
{
	// Ex: "f 1/1/1 2/2/2 3/3/3"
	FACE_FULL,
	// Ex: "f 1//1 2//2 3//3"
	FACE_POS_NORMAL,
	// Ex: "f 1/1 2/2 3/3"
	FACE_POS_TEX,
	// Ex: "f 1 2 3" (suportado)
	FACE_POS,
	FACE_UNSUPPORTED
};


class TriangleMesh
{
	friend class SimpleObjParser;
public:

	enum DrawMode
	{
		DRAW_TRIANGLES = 0x01,
		DRAW_EDGES     = 0x02,
		DRAW_VERTICES  = 0x04,
		/// Caixa envoltória, alinhada com os eixos
		DRAW_AABB  	    = 0x08
	};

	// NOTA: é necessário implementar os métodos de cópia quando usamos o objeto em um container
	TriangleMesh(const TriangleMesh& );
	TriangleMesh& operator=(const TriangleMesh& );

	TriangleMesh(void);
	virtual ~TriangleMesh(void);

	static void setupMaterial( const Material& m);

	static Vec3 triangleNormal( const Vec3& v0, const Vec3& v1, const Vec3& v2 );
	static Vec3 triangleNormal( const Vertex& v0, const Vertex& v1, const Vertex& v2 );

	const VertexArray& getVertices() const;

	void setDrawMode( unsigned char drawMode = TriangleMesh::DRAW_TRIANGLES );
	void setMaterial( const Material& m );


	void addVertex( float x, float y, float z=0.0f );
	void addVertex( const Vertex& v );
	void setHasNormals( bool b );
	bool getHasNormals() const;

	const Box3& getBoundingBox() const;

	virtual void clear();

	virtual void draw(void) const;
	virtual unsigned int getTriangleCount(void) const = 0;
	virtual unsigned int getVertexCount(void) const = 0;


	static Color edgeColor;
	static Color vertexColor;

protected:

	virtual void _drawTriangles(void) const = 0;
	virtual void _drawEdges(void) const = 0;
	virtual void _drawVertices(void) const = 0;

	VertexArray   vertices;
	Material   	  material;
	unsigned char drawModes;
	Box3          aabb;
	bool 		  hasNormals;
};

class RawTriangleMesh : public TriangleMesh
{
	friend class SimpleObjParser;
public:

	RawTriangleMesh(void);
	~RawTriangleMesh(void);

	virtual unsigned int getTriangleCount(void) const override;
	virtual unsigned int getVertexCount(void) const override;

protected:

	virtual void _drawTriangles(void) const override;
	virtual void _drawEdges(void) const override;
	virtual void _drawVertices(void) const override;

	/// Utilitário: entrega todos os vértices ao OpenGL via glVertex3f()
	void iterateVertices(void) const;


};

class IndexedTriangleMesh : public TriangleMesh
{
	friend class SimpleObjParser;
public:

	IndexedTriangleMesh(void);
	virtual ~IndexedTriangleMesh(void);

	IndexedTriangleMesh( const IndexedTriangleMesh& rhs );
	IndexedTriangleMesh& operator=( const IndexedTriangleMesh& rhs );

	virtual void clear() override;

	void addTriangle( unsigned int indV0, unsigned int indV1, unsigned int indV2 );

	virtual unsigned int getTriangleCount(void) const override;
	virtual unsigned int getVertexCount(void) const override;

protected:
	
	virtual void _drawTriangles(void) const override;
	virtual void _drawEdges(void) const override;
	virtual void _drawVertices(void) const override;

	IndexArray indices;
};


typedef std::vector<IndexedTriangleMesh> Scene;

Box3 getBoundingBox( const Scene& s );


#endif

