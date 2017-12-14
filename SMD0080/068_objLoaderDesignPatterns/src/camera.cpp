#include "camera.h"

Camera Camera::defaultCamera;

Camera::Camera()
: fovy(75), aspectRatio(1.0f), zNear(0.1f), zFar(1500), width(800), height(800), position(2,2,15), target(0,0,0), up( 0,1,0 )
{
}

void Camera::updateAspect(int w, int h)
{
	width = w, height = h;

	aspectRatio = width / std::max(1.0f, static_cast<double>(height));
}

Vector3D Camera::windowToNDC(int x, int y)
{
	Vector3D window(x, y);

	return Vector3D(2.0f * window.x / (float) width - 1.0f, 1.0f - 2.0f * window.y / (float) height);
}
