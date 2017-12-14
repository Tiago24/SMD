#ifndef MESHMATERIAL_CLASS_H
#define MESHMATERIAL_CLASS_H

#include "vec3.h"

struct Color
{
	const static  Color BLACK;
	const static  Color WHITE;
	const static  Color GRAY;
	const static  Color DARK_GRAY;
	const static  Color LIGHT_GRAY;

	const static  Color RED;
	const static  Color GREEN;
	const static  Color BLUE;


	Color( float cr=1, float cg=1, float cb=1, float ca=1 )
		: r(cr),g(cg),b(cb),a(ca)
	{
	}

	void clamp();

	float r,g,b,a;
};

std::ostream& operator<<( std::ostream& os, const Color& c );

/**
 *
 */
class Material
{
public:

	const static Material MT_EMERALD;
	const static Material MT_PEARL;
	const static Material MT_BRONZE;
	const static Material MT_GOLD;

	const static Material MT_CYAN_PLASTIC;
	const static Material MT_RED_PLASTIC;

	const static Material MT_BLACK_PLASTIC;
	const static Material MT_WHITE_PLASTIC;



	const static Material MT_GREEN_RUBBER;
	const static Material MT_YELLOW_RUBBER;
	const static Material MT_WHITE_RUBBER;

	Material( const String& nome = "<none>",
			const Color& Ka = Color::BLACK,
			const Color& Kd = Color::LIGHT_GRAY,
			const Color& Ks = Color::WHITE,
			float shininess = 1.0f,
			unsigned int tid = 0
			);
	Material( const Material& rhs );
	Material& operator=( const Material& rhs );

	bool hasTexture(void) const { return textureId>0; }

	/// Nome desse material
	String name;

	/// ambient
	Color ka;
	/// diffuse
	Color kd;
	/// specular
	Color ks;
	/// shininess: entre 0 e 1
	float ns;

	// id de textura
	unsigned int textureId;
};

typedef std::vector<Material> MaterialVector;

std::ostream& operator<<( std::ostream& os, const Material& m );

#endif


