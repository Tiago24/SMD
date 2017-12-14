#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "renderer.h"

// --------------------------------------------------------------------------
void Renderer::renderFrame(void)
{

}
// --------------------------------------------------------------------------
void Renderer::renderGroundPlane(float length, float y, unsigned int slices)
{
	const float delta = length / (float)(slices);
	length *= 0.5f;

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glBegin(GL_QUADS);
		glNormal3f(0,1,0);
		glColor3f(1,1,1);
		for( float x=-length; x<=length ; x+=delta )
		{
			for( float z=-length; z<=length ; z+=delta )
			{
				glVertex3f( x      , y, z       );
				glVertex3f( x+delta, y, z       );
				glVertex3f( x+delta, y, z-delta );
				glVertex3f( x      , y, z-delta );
			}
		}
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}
// --------------------------------------------------------------------------
void Renderer::renderBackground(void)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glDisable(GL_LIGHTING);
	glDepthMask(GL_FALSE);

	glBegin(GL_QUADS);
			glColor3f( 0.2, 0.2, 0.3);
			glVertex2f(-1,-1);
			glVertex2f(+1,-1);
			glColor3f( 0.8, 0.8, 1.0);
			glVertex2f(+1,+1);
			glVertex2f(-1,+1);
	glEnd();

	glDepthMask(GL_TRUE);
	glEnable(GL_LIGHTING);
}
// --------------------------------------------------------------------------
void Renderer::setupCamera( const Camera& cam )
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective( cam.fovy, cam.aspectRatio, cam.zNear, cam.zFar );

	// =======================================================
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt( cam.position.x, cam.position.y, cam.position.z,
			   cam.target.x  , cam.target.y  , cam.target.z  ,
			   cam.up.x      , cam.up.y      , cam.up.z      );
}
// --------------------------------------------------------------------------
void Renderer::renderScene( const Scene& scene )
{
	glDisable(GL_LIGHTING);
	glBegin(GL_LINES);
		float L = 10;
		glColor3f(1,0,0);
		glVertex3f(0,0,0);
		glVertex3f(L,0,0);

		glColor3f(0,1,0);
		glVertex3f(0,0,0);
		glVertex3f(0,L,0);

		glColor3f(0,0,1);
		glVertex3f(0,0,0);
		glVertex3f(0,0,L);
	glEnd();
	glEnable(GL_LIGHTING);

	for( auto& mesh : scene )
	{
		mesh.draw();
	}
}
// --------------------------------------------------------------------------
void Renderer::setupMaterial( const Material& m )
{
	// NOTA: habilita a configuração necessária
	glDisable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);

	glMaterialfv(GL_FRONT, GL_AMBIENT, &m.ka.r);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, &m.kd.r);
	glMaterialfv(GL_FRONT, GL_SPECULAR, &m.ks.r);
	glMaterialf(GL_FRONT, GL_SHININESS, m.ns * 128.0f);
}
// --------------------------------------------------------------------------
void Renderer::setupAllLights(void)
{
	glEnable( GL_LIGHTING );
	glEnable( GL_NORMALIZE );
	glShadeModel (GL_SMOOTH );

	// luz ambiente global
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, &Light::globalAmbientLight.r);

	for( unsigned int i=0; i<8 ; ++i )
	{
		if( i < Light::instances.size() )
		{
			const Light& luz = *(Light::instances[i]);
			setupLight( luz, i );
		}else
		{
			GLenum lid = GL_LIGHT0 + i;
			glDisable( lid );
		}
	}
}
// --------------------------------------------------------------------------
void Renderer::setupLight( const Light& luz, unsigned int id )
{
	if( id >= 8 ) return;

	// cor da luz
	const GLenum lid = GL_LIGHT0 + id;
	glEnable( lid );
	glLightfv(lid, GL_AMBIENT , &luz.ambient.r );
	glLightfv(lid, GL_DIFFUSE , &luz.diffuse.r );
	glLightfv(lid, GL_SPECULAR, &luz.specular.r );

	// atenuação
	glLightf( lid, GL_CONSTANT_ATTENUATION, luz.kc);
	glLightf( lid, GL_LINEAR_ATTENUATION, luz.kl);
	glLightf( lid, GL_QUADRATIC_ATTENUATION, luz.kq);

	// posição
	if( luz.lightType ==  Light::LT_DIRECTIONAL )
	{
		// é mais intuitivo usar a direção
		GLfloat pos[4] = { -luz.direction.x, -luz.direction.y, -luz.direction.z, 0 };
		glLightfv(lid, GL_POSITION, pos);
	}else
	{
		GLfloat pos[4] = { luz.position.x, luz.position.y, luz.position.y, 1.0 };
		glLightfv(lid, GL_POSITION, pos);
	}

	if( luz.lightType ==  Light::LT_SPOTLIGHT )
	{

		glLightfv( lid, GL_SPOT_DIRECTION, &luz.direction.x);
	}

	// cutoff
	float cutoff = ( luz.lightType ==  Light::LT_SPOTLIGHT ) ? luz.spotCutoff : 180.0;
	glLightf( lid , GL_SPOT_CUTOFF, cutoff );

	float exponent = ( luz.lightType ==  Light::LT_SPOTLIGHT ) ? luz.spotExponent : 0.0;
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, exponent);



}
// --------------------------------------------------------------------------

