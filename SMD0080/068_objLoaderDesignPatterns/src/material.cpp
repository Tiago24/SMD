#include <material.h>

// ------------------------------------------------------------------------------------------
// Constantes de Color
// ------------------------------------------------------------------------------------------
const Color Color::BLACK(0,0,0);
const Color Color::WHITE(1,1,1);
const Color Color::GRAY(0.5f,0.5f,0.5f);
const Color Color::DARK_GRAY(0.25f,0.25f,0.25f);
const Color Color::LIGHT_GRAY(0.75f,0.75f,0.75f);
const Color Color::RED  (1,0,0);
const Color Color::GREEN(0,1,0);
const Color Color::BLUE (0,0,1);
// ------------------------------------------------------------------------------------------
void Color::clamp(void)
{
	r = std::max( 0.0f, std::min(1.0f,r) );
	g = std::max( 0.0f, std::min(1.0f,g) );
	b = std::max( 0.0f, std::min(1.0f,b) );
	a = std::max( 0.0f, std::min(1.0f,a) );
}
// ------------------------------------------------------------------------------------------
std::ostream& operator<<( std::ostream& os, const Color& c )
{
	return std::cout << c.r << ' ' << c.g << ' ' << c.b << ' ' << c.a << std::endl;
}
// ------------------------------------------------------------------------------------------
// Constantes de Material: http://devernay.free.fr/cours/opengl/materials.html
// ------------------------------------------------------------------------------------------
const Material Material::MT_EMERALD("emerald",
		  Color(0.0215f,0.17450f,0.0215f),
		  Color(0.07568f,0.614240f,0.07568f),
		  Color(0.0f,0.0f,0.0f),
		  0.6f);
const Material Material::MT_PEARL("pearl",
		  Color(0.0f,0.0f,0.0f),
		  Color(0.0f,0.0f,0.0f),
		  Color(0.0f,0.0f,0.0f),
		  0.0f);
const Material Material::MT_BRONZE("bronze",
		  Color(0.0f,0.0f,0.0f),
		  Color(0.0f,0.0f,0.0f),
		  Color(0.0f,0.0f,0.0f),
		  0.0f);
const Material Material::MT_GOLD("gold",
		  Color(0.24725f,0.1995f,0.0745f),
		  Color(0.75164f,0.60648f,0.22648f),
		  Color(0.628281f,0.555802f,0.366065f),
		  0.4f);

const Material Material::MT_WHITE_PLASTIC("white_plastic",
										  Color(0.0f,0.0f,0.0f),
										  Color(0.0f,0.0f,0.0f),
										  Color(0.0f,0.0f,0.0f),
										  0.0f
		);
const Material Material::MT_BLACK_PLASTIC("black_plastic",
		  Color(0.0f,0.0f,0.0f),
		  Color(0.0f,0.0f,0.0f),
		  Color(0.0f,0.0f,0.0f),
		  0.0f);
const Material Material::MT_CYAN_PLASTIC("cyan_plastic",
		  Color(0.0f,0.0f,0.0f),
		  Color(0.0f,0.0f,0.0f),
		  Color(0.0f,0.0f,0.0f),
		  0.0f);
const Material Material::MT_RED_PLASTIC("red_plastic",
		  Color(0.0f,0.0f,0.0f),
		  Color(0.0f,0.0f,0.0f),
		  Color(0.0f,0.0f,0.0f),
		  0.0f);

const Material Material::MT_GREEN_RUBBER("green_rubber",
		  Color(0.0f,0.0f,0.0f),
		  Color(0.0f,0.0f,0.0f),
		  Color(0.0f,0.0f,0.0f),
		  0.0f);
const Material Material::MT_YELLOW_RUBBER("yellow_rubber",
		  Color(0.0f,0.0f,0.0f),
		  Color(0.0f,0.0f,0.0f),
		  Color(0.0f,0.0f,0.0f),
		  0.0f);
const Material Material::MT_WHITE_RUBBER("white_rubber",
		  Color(0.05f,0.05f,0.05f),
		  Color(0.5f,0.5f,0.5f),
		  Color(0.7f,0.7f,0.7f),
		  0.078125f);
// ------------------------------------------------------------------------------------------
// Material
// ------------------------------------------------------------------------------------------
Material::Material( const String& nome,
			const Color& Ka,
			const Color& Kd,
			const Color& Ks,
			float shininess,
			unsigned int tid
			)
			: name(nome),
			  ka(Ka),
			  kd(Kd ),
			  ks(Ks),
			  ns(shininess),
			  textureId(tid)
{
}
// ------------------------------------------------------------------------------------------
Material::Material( const Material& rhs )
			: name(rhs.name),
			  ka(rhs.ka),
			  kd(rhs.kd),
			  ks(rhs.ks),
			  ns(rhs.ns),
			  textureId(rhs.textureId)
{
}
// ------------------------------------------------------------------------------------------
Material& Material::operator=( const Material& rhs )
{
	if( this != &rhs )
	{
		name = rhs.name;
		ka = rhs.ka;
		kd = rhs.kd;
		ks = rhs.ks;
		ns = rhs.ns;
		textureId = rhs.textureId;
	}
	return *this;
}
// ------------------------------------------------------------------------------------------
std::ostream& operator<<( std::ostream& os, const Material& m )
{
	return os << "Material: " << m.name << std::endl
			<< "Ka: " << m.ka << std::endl
			<< "Kd: " << m.kd << std::endl
			<< "Ks: " << m.ks << std::endl
			<< "shininess: " << m.ns << std::endl;
}
// ------------------------------------------------------------------------------------------

