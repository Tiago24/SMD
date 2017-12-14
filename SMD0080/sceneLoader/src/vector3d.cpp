#include "vector3d.h"

const Vector3D Vector3D::ZERO(0,0,0);
const Vector3D Vector3D::X_AXIS(1,0,0);
const Vector3D Vector3D::Y_AXIS(0,1,0);
const Vector3D Vector3D::Z_AXIS(0,0,1);

std::ostream& operator<<(std::ostream& os, const Vec2& v)
{
	return os << v.x << ' ' << v.y;
}

std::ostream& operator<<(std::ostream& os, const Vector3D& v)
{
	return os << v.x << ' ' << v.y << ' ' << v.z;
}
