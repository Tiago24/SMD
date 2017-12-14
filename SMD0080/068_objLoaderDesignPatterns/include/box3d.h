#ifndef BOX3D_CLASS_H
#define BOX3D_CLASS_H

#include "vector3d.h"

#include <cfloat>
#include <algorithm>


#undef min
#undef max

class Box3D
{
public:
	Box3D();
	
	void add(const Vector3D& v);
	Vector3D extents() const;
	Vector3D center() const;
	float getScale() const;

	Vector3D min;
	Vector3D max;
};

#endif
