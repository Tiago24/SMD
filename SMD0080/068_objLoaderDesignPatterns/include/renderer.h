/*
 * renderer.h
 *
 *  Created on: 29 de jan de 2017
 *      Author: gilvan
 */

#ifndef INCLUDE_RENDERER_H_
#define INCLUDE_RENDERER_H_

#include "camera.h"
#include "light.h"

class Renderer
{
public:

	static void renderFrame(void);

	static void renderGroundPlane(float length = 100, float height=0.0f, unsigned int slices=20);
	static void renderBackground(void);
	static void renderScene( const Scene& scene );
	static void setupCamera( const Camera& cam );
	static void setupMaterial( const Material& m );
	static void setupAllLights(void);

protected:
	static void setupLight( const Light& luz, unsigned int id );
};



#endif /* INCLUDE_RENDERER_H_ */
