#ifndef CAMERA_CLASS_H
#define CAMERA_CLASS_H

#include "triangleMesh.h"

struct Camera
{
	static Camera defaultCamera;

	Camera();

	void updateAspect(int width, int height);
	Vector3D windowToNDC(int x, int y);

	double fovy;
	double aspectRatio;
	double zNear;
	double zFar;

	unsigned int width;
	unsigned int height;

	Vector3D position;
	Vector3D target;
	Vector3D up;
};

#endif /* CAMERA_CLASS_H */
