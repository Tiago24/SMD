#ifndef BOX3_CLASS_H
#define BOX3_CLASS_H

#include "vec3.h"

#include <cfloat>
#include <algorithm>


#undef min
#undef max

class Box3
{
public:
	Box3()
		: min( +FLT_MAX,+FLT_MAX,+FLT_MAX ),
		  max( -FLT_MAX,-FLT_MAX,-FLT_MAX )
	{
	}
	
	void add( const Vec3& v )
	{
		min.x = std::min( min.x, v.x);
		min.y = std::min( min.y, v.y);
		min.z = std::min( min.z, v.z);

		max.x = std::max( max.x, v.x);
		max.y = std::max( max.y, v.y);
		max.z = std::max( max.z, v.z);
	}
	Vec3 extents() const
	{
		return (max-min)*0.5f;
	}
	Vec3 center() const
	{
		return (max+min)*0.5f;
	}


	float getScale() const
	{
		float s = 0.0f;
		const float* coords = &min.x;

		for( int i=0; i<6 ; i++)
			s = std::max ( s, std::fabs( coords[i] ) );

		return s*1.5f;
	}

	Vec3 min;
	Vec3 max;
};

#endif

