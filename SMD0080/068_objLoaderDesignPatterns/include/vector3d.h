#ifndef VECTOR3D_CLASS_H
#define VECTOR3D_CLASS_H

#include "vector2D.h"

class Vector3D
{
public:
	const static Vector3D ZERO;
	const static Vector3D X_AXIS;
	const static Vector3D Y_AXIS;
	const static Vector3D Z_AXIS;

	Vector3D()
		 : x(0), y(0), z(0)
	{}

	Vector3D( float xx, float yy, float zz=1.0f )
	 : x(xx), y(yy), z(zz)
	{}
	Vector3D( const Vector3D& v )
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

	float distance( const Vector3D& v ) const
	{
		const float dx = x - v.x;
		const float dy = y - v.y;
		const float dz = z - v.z;

		return sqrt( dx*dx + dy*dy + dz*dz );
	}

	float distance2( const Vector3D& v ) const
	{
		const float dx = x - v.x;
		const float dy = y - v.y;
		const float dz = z - v.z;

		return dx*dx + dy*dy + dz*dz;
	}
	Vector3D cross(const Vector3D& v) const
	{
		return Vector3D( y*v.z - z*v.y,
					   z*v.x - x*v.z,
					   x*v.y - y*v.x );
	}

	Vector3D operator-(const Vector3D& v) const
	{
		return Vector3D( x-v.x, y-v.y, z-v.z );
	}
	Vector3D operator+(const Vector3D& v) const
	{
		return Vector3D( x+v.x, y+v.y, z+v.z );
	}
	Vector3D operator-() const
	{
		return Vector3D( -x,-y,-z);
	}
	Vector3D& normalize()
	{
		return (*this) /= magnitude();
	}
	Vector3D operator*(float f) const
	{
		return Vector3D(x*f,y*f,z*f);
	}

	friend Vector3D operator*(float f, const Vector3D& v)
	{
		return Vector3D(v.x*f,v.y*f,v.z*f);
	}

	Vector3D& operator /=(float f)
	{
		x /= f;
		y /= f;
		z /= f;

		return *this;
	}

	Vector3D& operator =( const Vector3D& v )
	{
		x = v.x;
		y = v.y;
		z = v.z;

		return *this;
	}

	Vector3D& operator +=( const Vector3D& v )
	{
		x += v.x;
		y += v.y;
		z += v.z;

		return *this;
	}

	Vector3D& operator -=( const Vector3D& v )
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;

		return *this;
	}


	float x, y, z;
};

std::ostream& operator <<( std::ostream& os, const Vector2D& v  );
std::ostream& operator <<( std::ostream& os, const Vector3D& v  );

#endif /* VECTOR3D_CLASS_H */

