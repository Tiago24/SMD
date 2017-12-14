#ifndef SIMPLELIGHT_CLASS_H
#define SIMPLELIGHT_CLASS_H

#include "triangleMesh.h"

class Light
{
	friend class Renderer;

public:
	typedef std::vector<Light*> LightVector;

protected:

	static LightVector instances;

public:

	/// Luz mínima da cena em luz ambiente
	static Color globalAmbientLight;


	enum LightType
	{
		/// Como a luz do sol
		LT_DIRECTIONAL,
		/// Como uma lâmpada ideal, pontual e omnidirecional
		LT_POINT,
		/// Como um holofote
		LT_SPOTLIGHT
	};

	Light();
	~Light();

	// ---------------------------------------------------------------------------------
	// características da cor
	// ---------------------------------------------------------------------------------

	/// Componente ambiente. Há uma global e uma por luz
	Color ambient;
	/// Componente difusa
	Color diffuse;
	/// Componente especular
	Color specular;

	// ---------------------------------------------------------------------------------
	// características geométricas
	// ---------------------------------------------------------------------------------

	Vec3  position;
	Vec3  direction;
	float spotCutoff;
	/// Indica o quão concentrada é a luz no centro do holofote
	float spotExponent;


	/* Fator de atenuação da potência luz, onde d é a distância entre
	 * a fonte da luz e o ponto sendo iluminado é calculado usando um
	 * polinômio do 2º grau:
	 *  fa = 1 / ( kc + kl*d + kq*d^2 )
	 */

	/// Constante de atenuação (sempre presente)
	float kc;
	/// Constante linear de atenuação
	float kl;
	/// Constante quadrática de atenuação
	float kq;

	LightType lightType;
};


#endif /* SIMPLELIGHT_CLASS_H */
