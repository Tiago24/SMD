#ifndef MESHVERTEX_CLASS_H
#define MESHVERTEX_CLASS_H

#include "vec3.h"

struct Vertex
{
	Vertex()
		: position(), normal(), texture()
	{
	}
	Vertex(const Vec3& pos, const Vec3& n=Vec3(), const Vec2& tex = Vec2() )
		: position(pos), normal(n), texture(tex)
	{
	}

	Vec3 position;
	Vec3 normal;
	Vec2 texture;
};


#endif


