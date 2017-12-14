#ifndef INDEXEDMESH_CLASS_H
#define INDEXEDMESH_CLASS_H

#include <material.h>
#include "box3.h"
#include "meshVertex.h"
#include "triangleMesh.h"

class IndexedTriangleMesh : public TriangleMesh
{
	friend class SimpleObjParser;
public:

	IndexedTriangleMesh(void);
	virtual ~IndexedTriangleMesh(void);

	IndexedTriangleMesh(const IndexedTriangleMesh& rhs);
	IndexedTriangleMesh& operator=(const IndexedTriangleMesh& rhs);

	virtual void clear() override;

	void addTriangle(unsigned int indV0, unsigned int indV1, unsigned int indV2);

	virtual unsigned int getTriangleCount(void) const override;
	virtual unsigned int getVertexCount(void) const override;

protected:
	
	virtual void _drawTriangles(void) const override;
	virtual void _drawEdges(void) const override;
	virtual void _drawVertices(void) const override;

	IndexArray indices;
};

typedef std::vector<IndexedTriangleMesh> Scene;

Box3D getBoundingBox(const Scene& s);

#endif
