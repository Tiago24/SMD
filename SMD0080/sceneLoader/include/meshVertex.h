#ifndef MESHVERTEX_CLASS_H
#define MESHVERTEX_CLASS_H

#include "vector3d.h"

struct Vertex
{
	Vertex()
		: position(), normal(), texture()
	{
	}

	Vertex(const Vector3D& pos, const Vector3D& n = Vector3D(), const Vec2& tex = Vec2())
		: position(pos), normal(n), texture(tex)
	{
	}

	Vector3D position;
	Vector3D normal;
	Vector2D texture;
};

#endif
