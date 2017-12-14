#include "light.h"

// ---------------------------------------------------------------------------------
Light::LightVector Light::instances;
// ---------------------------------------------------------------------------------
Color Light::globalAmbientLight (0.2, 0.2, 0.2, 1.0);
// ---------------------------------------------------------------------------------
Light::Light()
	: ambient(0.2,0.2,0.2,1.0),
	  diffuse(1,1,1,1),
	  specular(1,1,1,1),
	  position(1,1,0),
	  direction(0,0,-1),
	  spotCutoff(180),
	  spotExponent(0),
	  kc(1),
	  kl(0),
	  kq(0),
	  lightType(Light::LT_DIRECTIONAL)
{
	Light::instances.push_back(this);
}
// ---------------------------------------------------------------------------------
Light::~Light()
{
	Light::LightVector::iterator it = std::find( Light::instances.begin(), Light::instances.end(), this );

	if( it != Light::instances.end() )
	{
		Light::instances.erase(it);
	}
}
// ---------------------------------------------------------------------------------
