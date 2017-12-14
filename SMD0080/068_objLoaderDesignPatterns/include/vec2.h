#ifndef VEC2D_CLASS_H
#define VEC2D_CLASS_H

#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>

typedef std::string String;
typedef std::istringstream StringInputStream;

class Vec2
{
public:

	const static Vec2 ZERO;
	const static Vec2 X_AXIS;
	const static Vec2 Y_AXIS;

	Vec2( float xx=0, float yy=0 )
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

	float distance( const Vec2& v ) const
	{
		const float dx = x - v.x;
		const float dy = y - v.y;

		return sqrt( dx*dx + dy*dy );
	}

	float distance2( const Vec2& v ) const
	{
		const float dx = x - v.x;
		const float dy = y - v.y;

		return dx*dx + dy*dy;
	}
	float cross(const Vec2& v) const
	{
		return x*v.y - y*v.x;
	}

	Vec2 operator-(const Vec2& v) const
	{
		return Vec2( x-v.x, y-v.y );
	}
	Vec2 operator-() const
	{
		return Vec2( -x, -y );
	}

	Vec2& normalize()
	{
		return (*this) /= magnitude();
	}

	Vec2& operator /=(float f)
	{
		x /= f;
		y /= f;

		return *this;
	}

	Vec2& operator =( const Vec2& v )
	{
		x = v.x;
		y = v.y;

		return *this;
	}


	float x, y;
};

#endif

