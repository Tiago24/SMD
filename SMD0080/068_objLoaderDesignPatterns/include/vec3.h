#ifndef VECTOR3D_CLASS_H
#define VECTOR3D_CLASS_H

#include "vec2.h"

class Vec3
{
public:
	const static Vec3 ZERO;
	const static Vec3 X_AXIS;
	const static Vec3 Y_AXIS;
	const static Vec3 Z_AXIS;

	Vec3()
		 : x(0), y(0), z(0)
	{}

	Vec3( float xx, float yy, float zz=1.0f )
	 : x(xx), y(yy), z(zz)
	{}
	Vec3( const Vec3& v )
	 : x(v.x), y(v.y), z(v.z)
	{}

	float magnitude() const
	{
		return sqrt( x*x + y*y + z*z );
	}
	float magnitude2() const
	{
		return ( x*x + y*y + z*z );
	}

	float distance( const Vec3& v ) const
	{
		const float dx = x - v.x;
		const float dy = y - v.y;
		const float dz = z - v.z;

		return sqrt( dx*dx + dy*dy + dz*dz );
	}

	float distance2( const Vec3& v ) const
	{
		const float dx = x - v.x;
		const float dy = y - v.y;
		const float dz = z - v.z;

		return dx*dx + dy*dy + dz*dz;
	}
	Vec3 cross(const Vec3& v) const
	{
		return Vec3( y*v.z - z*v.y,
					   z*v.x - x*v.z,
					   x*v.y - y*v.x );
	}

	Vec3 operator-(const Vec3& v) const
	{
		return Vec3( x-v.x, y-v.y, z-v.z );
	}
	Vec3 operator+(const Vec3& v) const
	{
		return Vec3( x+v.x, y+v.y, z+v.z );
	}
	Vec3 operator-() const
	{
		return Vec3( -x,-y,-z);
	}
	Vec3& normalize()
	{
		return (*this) /= magnitude();
	}
	Vec3 operator*(float f) const
	{
		return Vec3(x*f,y*f,z*f);
	}

	friend Vec3 operator*(float f, const Vec3& v)
	{
		return Vec3(v.x*f,v.y*f,v.z*f);
	}

	Vec3& operator /=(float f)
	{
		x /= f;
		y /= f;
		z /= f;

		return *this;
	}

	Vec3& operator =( const Vec3& v )
	{
		x = v.x;
		y = v.y;
		z = v.z;

		return *this;
	}

	Vec3& operator +=( const Vec3& v )
	{
		x += v.x;
		y += v.y;
		z += v.z;

		return *this;
	}

	Vec3& operator -=( const Vec3& v )
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;

		return *this;
	}


	float x, y, z;
};

std::ostream& operator <<( std::ostream& os, const Vec2& v  );
std::ostream& operator <<( std::ostream& os, const Vec3& v  );

#endif /* VECTOR3D_CLASS_H */

