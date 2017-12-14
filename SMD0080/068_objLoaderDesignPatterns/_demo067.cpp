#include "renderer.h"
#include "loader/objTextFileParser.h"

#include <GL/gl.h>
#include <GL/glut.h>

#include <IL/il.h>
#include <IL/ilu.h>
#include <IL/ilut.h>

// o truque do mapeamento ;)
const char* objFilename = "models/coffee.obj";

static Camera& camera = Camera::defaultCamera;
static Scene* scene = nullptr;
static bool msaaEnabled = false;
static Box3 box;

static void meuPintaCena();
static void trataEventosDeTeclado(unsigned char key, int x, int y);
static void trataRedimensionamentoDeJanela( int w, int h);


int main( int argc, char** argv )
{
	scene = ObjTextFileParser( objFilename ).parseScene();
	box = getBoundingBox(*scene);


	glutInit( &argc, argv );
	glutInitWindowSize( camera.width, camera.height );
	//glutInitWindowSize( 800, 800 );
	glutInitWindowPosition(10,10);
	/** Antialiasing usando MSAA (novo!)
	 *  1) Habilitar a inicialização com GLUT_MULTISAMPLE em glutInitDisplayMode()
	 *  2) Habilitar o antialiasing via glEnable( GL_MULTISAMPLE )
	 *  3) NOTA: só funciona se a extensão "GL_ARB_multisample" estiver presente no seu driver
	 *  4) NOTA: só funciona se a configuração geral do seu driver/Desktop [não impedir].
	 *
	 *  Confira alguns detalhes técnicos dos métodos de MSAA em https://mynameismjp.wordpress.com/2012/10/24/msaa-overview/
	 */
	glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH | GLUT_STENCIL | GLUT_MULTISAMPLE );
	
	glutCreateWindow( "OBJ + Design Patterns = Light & Texture" );
	glutReshapeFunc( trataRedimensionamentoDeJanela );
	glutDisplayFunc( meuPintaCena );	
	glutKeyboardFunc( trataEventosDeTeclado );
	
	// configurações globais
	glPointSize( 8.0f );
	glLineWidth( 1.5f );

	{
		// inicialização da biblioteca de carregamento de texturas
		ilInit();
		iluInit();
		ilutInit();
		ilEnable(IL_FILE_OVERWRITE);


		ILuint texid;
		ilGenImages( 1, &texid );
		ilBindImage(texid);
	}

	glutMainLoop();
	
	return 0;
}

void trataRedimensionamentoDeJanela( int w, int h)
{
	glViewport( 0,0, w, h );
	camera.updateAspect(w,h);
}

static void meuPintaCena()
{	
	// =======================================================
	glClearColor(1,1,1,0);
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT );
	
	// NOVO: antialiasing
	if( msaaEnabled )
	{
		glEnable( GL_MULTISAMPLE );
	}
	else
	{
		glDisable( GL_MULTISAMPLE );
	}

	// =======================================================
	// Cena principal
	// =======================================================
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	camera.up = Vec3::Y_AXIS;
	Renderer::renderBackground();
	Renderer::setupCamera(camera);

	// várias luzes ?
	Light luz;
	luz.lightType = Light::LT_POINT;
	luz.position.y = box.max.y*1.5f;
	/*Light spot;
	{
		// NOTA: o ideal é trazer as luzes do editor
		spot.lightType = Light::LT_SPOTLIGHT;
		spot.position = Vec3(100,100,100 );
		spot.direction = Vec3(-1,-1,-1);
		spot.spotCutoff = 45.0f;
	}*/

	Renderer::setupAllLights();

	if( scene )
		Renderer::renderScene(*scene);

	// =========================================================
	Renderer::setupMaterial( Material::MT_EMERALD );
	Renderer::renderGroundPlane( 1500, box.min.y, 100 );

	
	glutSwapBuffers();
	glutPostRedisplay();	
}

void trataEventosDeTeclado( unsigned char key, int x, int y)
{
	switch(key)
	{
	case 'W': case 'w': case GLUT_KEY_UP:
		camera.position += (camera.target-camera.position).normalize();
		break;
	case 's': case 'S': case GLUT_KEY_DOWN:
		camera.position -= (camera.target-camera.position).normalize();
		break;
	case 'a': case 'A': //case GLUT_KEY_LEFT:
	{
		Vec3 localX = (camera.target-camera.position).cross( camera.up ).normalize();
		camera.position -= localX;
		break;
	}
	case 'd': case 'D': case GLUT_KEY_RIGHT:
	{
		Vec3 localX = (camera.target-camera.position).cross( camera.up ).normalize();
		camera.position += localX;
	}
		break;
	case 'm': case 'M':
		if( msaaEnabled )
		{
			GLint numSamples = 0;
			glGetIntegerv(GL_SAMPLES, &numSamples);
			printf("MSAA utiliza %d amostras \n", numSamples);
		}
		msaaEnabled = !msaaEnabled;
		break;
	// Tecla "ESC"
	case 27:
		exit(-1);
		break; 	
	}
}

