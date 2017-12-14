#include "box3d.h"

Box3D::Box3D()
: min(+FLT_MAX, +FLT_MAX, +FLT_MAX), max(-FLT_MAX, -FLT_MAX, -FLT_MAX)
{
}

void Box3D::add(const Vector3D& v)
{
	min.x = std::min(min.x, v.x);
	min.y = std::min(min.y, v.y);
	min.z = std::min(min.z, v.z);

	max.x = std::max(max.x, v.x);
	max.y = std::max(max.y, v.y);
	max.z = std::max(max.z, v.z);
}

Vector3D Box3D::extents() const
{
	return (max - min) * 0.5f;
}

Vector3D Box3D::center() const
{
	return (max + min) * 0.5f;
}


float Box3D::getScale() const
{
	float s = 0.0f;
	const float* coords = &min.x;

	for(int i = 0; i < 6; i++)
		s = std::max(s, std::fabs(coords[i]));

	return s * 1.5f;
}
