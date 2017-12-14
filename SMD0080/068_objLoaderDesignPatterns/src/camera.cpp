#include "camera.h"

// --------------------------------------------------------------------------
Camera Camera::defaultCamera;
// --------------------------------------------------------------------------
// Camera
// --------------------------------------------------------------------------
Camera::Camera()
	: fovy(75),
	  aspectRatio(1.0f),
	  zNear(0.1f),
	  zFar(1500),
	  width(800),
	  height(800),

	  position(2,2,15),
	  target(0,0,0),
	  up( 0,1,0 ) // bug aqui, se usar Vec3::Y_AXIS
{
	// NOTA: "The C++ Static Initialization Order Fiasco"

	// The C++ Static Initialization Order Fiasco is a well known problem with C++ programs
	// that use static class objects. The problem concerns class objects with non-trivial
	// constructors (like allocating a buffer), and not plain old datatypes (POD) (like integers and pointers) -- Oct 31, 2016
}
// --------------------------------------------------------------------------
void Camera::updateAspect( int w, int h )
{
	width = w, height = h;

	aspectRatio = width / std::max( 1.0, static_cast<double>(height) );
}
// --------------------------------------------------------------------------
Vec3 Camera::windowToNdc( int x, int y )
{
	Vec3 window( x, y );

	return Vec3( 2.0f*window.x/ float(width) - 1.0f,
				 1.0f                        - 2.0f*window.y/ float(height) );
}
// --------------------------------------------------------------------------
