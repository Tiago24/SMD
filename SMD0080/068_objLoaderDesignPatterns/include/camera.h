#ifndef SIMPLECAMERA_CLASS_H
#define SIMPLECAMERA_CLASS_H

#include "triangleMesh.h"

struct Camera
{
	/// Câmera padrão, evita dores de cabeça
	static Camera defaultCamera;

	/// Construtor padrão
	Camera();

	void updateAspect( int width, int height );
	Vec3 windowToNdc( int x, int y );

	// ================================
	// Usado na projeção em perspectiva
	double fovy;
	double aspectRatio;
	double zNear;
	double zFar;

	// ================================
	// Usado para resolver aspecto, etc
	unsigned int width;
	unsigned int height;

	// ================================
	// Usado no posicionamento
	Vec3 position;
	Vec3 target;
	Vec3 up;
};


#endif /* SIMPLECAMERA_CLASS_H */
