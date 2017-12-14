#ifndef VECTOR2D_CLASS_H
#define VECTOR2D_CLASS_H

#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>

typedef std::string String;
typedef std::istringstream StringInputStream;

class Vector2D
{
public:

	const static Vector2D ZERO;
	const static Vector2D X_AXIS;
	const static Vector2D Y_AXIS;

	Vector2D( float xx=0, float yy=0 )
	 : x(yy), y(yy)
	{}

	float magnitude() const
	{
		return sqrt( x*x + y*y );
	}
	float magnitude2() const
	{
		return ( x*x + y*y );
	}

	float distance( const Vector2D& v ) const
	{
		const float dx = x - v.x;
		const float dy = y - v.y;

		return sqrt( dx*dx + dy*dy );
	}

	float distance2( const Vector2D& v ) const
	{
		const float dx = x - v.x;
		const float dy = y - v.y;

		return dx*dx + dy*dy;
	}
	float cross(const Vector2D& v) const
	{
		return x*v.y - y*v.x;
	}

	Vector2D operator-(const Vector2D& v) const
	{
		return Vector2D( x-v.x, y-v.y );
	}
	Vector2D operator-() const
	{
		return Vector2D( -x, -y );
	}

	Vector2D& normalize()
	{
		return (*this) /= magnitude();
	}

	Vector2D& operator /=(float f)
	{
		x /= f;
		y /= f;

		return *this;
	}

	Vector2D& operator =( const Vector2D& v )
	{
		x = v.x;
		y = v.y;

		return *this;
	}

	float x, y;
};

#endif
