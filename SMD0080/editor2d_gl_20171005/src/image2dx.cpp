#include "image2dx.h"

// NOVO: o include do OpenGL está aqui pois não precisamos saber como ela é pintada
#include <GL/gl.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// =========================================================================================
// Classe Imagem
// =========================================================================================
Image::Image()
	: pixels(0), buffer(0), width(0), height(0)
{
}
// =========================================================================================
Image::Image( const Image& img )
	: pixels(0), buffer(0), width(0), height(0)
{
	// NOVO reusa o operador de cópia
	*this = img;
}
// =========================================================================================
Image::Image( pixel bg, int w, int h )
	: pixels(0), buffer(0), width(0), height(0)
{
	_allocate(w,h);
	
	clear(bg);
}
// =========================================================================================
Image& Image::operator=( const Image& img )
{
	if( this != &img )
	{
		_allocate( img.width, img.height );

		std::memcpy( buffer, img.buffer, sizeof(pixel)*width*height );
	}

	return *this;

}
// =========================================================================================
Image::~Image()
{
	_deallocate();
}
// =========================================================================================
void Image::_allocate( int w, int h )
{
	if( w == width && h == height )
		return;

	_deallocate();

	// alocacao
	width = w, height = h;
	pixels = new pixel_row[ height ];
	buffer = new pixel[ width*height ];

	pixel* it = buffer;
	for( int i=0; i<height ; ++i, it+=w )
	{
		//pixels[i] = &buffer[ i*width ];
		pixels[i] = it;
	}
}
// =========================================================================================
void Image::_deallocate()
{
	if( pixels )
	{
		delete [] buffer;
		delete [] pixels;

		pixels = 0;
		width = height = 0;
	}
}
// =========================================================================================
void Image::hline( pixel cor, int y, int x1, int x2 )
{
	if( y < 0 || y >= height )
		return;

	const int minX = std::max( std::min(x1,x2),         0 );
	if( minX >= width )
		return;

	const int maxX = std::min( std::max(x1,x2), width - 1 );
	if( maxX < 0 )
			return;

#if 0

	for( int x = minX; x <= maxX ; ++x )
	{
		setPixel(cor, x, y);
	}
#else
	pixel* it     = pixels[y] + minX;
	pixel* theEnd = pixels[y] + maxX;

	do
	{
		*it++ = cor;
	}while( it <= theEnd  );

#endif
}
// =========================================================================================
void Image::vline( pixel cor, int x, int y1, int y2 )
{
	if( x < 0 || x >= width )
		return;

	const int minY = std::max( std::min(y1,y2),          0 );
	if( minY >= height  )
		return;

	const int maxY = std::min( std::max(y1,y2), height - 1 );
	if( maxY < 0  )
		return;

	for( int y = minY; y <= maxY ; ++y )
	{
		setPixel(cor, x, y);
	}
}
// =========================================================================================
void Image::drawRect( pixel cor, int x1, int y1, int x2, int y2 )
{
	const int minX = std::min( x1, x2 );
	const int minY = std::min( y1, y2 );
	const int maxX = std::max( x1, x2 );
	const int maxY = std::max( y1, y2 );

	hline( cor, minY, minX, maxX );
	hline( cor, maxY, minX, maxX );

	vline( cor, minX, minY, maxY );
	vline( cor, maxX, minY, maxY );

}
// =========================================================================================
void Image::fillRect( pixel cor, int x1, int y1, int x2, int y2 )
{
	int minX = std::min( x1, x2 );
	int minY = std::min( y1, y2 );
	int maxX = std::max( x1, x2 );
	int maxY = std::max( y1, y2 );

	if( maxX < 0 || maxY <0 || minX >= width || minY >= height )
		return;

	minX = std::max( minX, 0 );
	minY = std::max( minY, 0 );
	maxX = std::min( maxX, width-1 );
	maxY = std::min( maxY, height-1 );



	for( int y =minY ; y<=maxY; ++y )
		hline( cor, y, minX, maxX );

}
// =========================================================================================
void Image::lineMidPoint( pixel cor, int x1, int y1, int x2, int y2  )
{
#if 1
	const int dx = abs(x2-x1);
	const int dy = abs(y2-y1);

	setPixelSafe(cor, x1,y1 );
	setPixelSafe(cor, x2,y2 );

	if( dx <= 1 && dy <= 1 )
	{

	}
#else
	// nunca faça isso: pois a recursão é infinita
	if( (x1 == x2) && (y1 == y2) )
	{
		setPixelSafe(cor, x1,y1);
	}
#endif
	else
	{
		const int mx = (x1+x2)>>1;
		const int my = (y1+y2)>>1;

		lineMidPoint( cor, x1,y1, mx, my);
		lineMidPoint( cor, mx, my, x2,y2);
	}

}
// =========================================================================================
void Image::lineDDA( pixel cor, int x1, int y1, int x2, int y2  )
{
	int dx = x2 - x1;
	int dy = y2 - y1;

	int step = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);

	float stepX = dx / (float) step;
	float stepY = dy / (float) step;
	float x = (float) x1;
	float y = (float) y1;

	for(int i = 0; i <= step; ++i)
	{
		setPixelSafe(cor, x, y);
		x += stepX;
		y += stepY;
	}
}
// =========================================================================================
void Image::lineBresenham( pixel cor, int x1, int y1, int x2, int y2  )
{
	const bool step = (abs(y2 - y1) > abs(x2 - x1));
	if(step)
	{
		std::swap(x1, y1);
		std::swap(x2, y2);
	}
	if(x1 > x2)
	{
		std::swap(x1, x2);
		std::swap(y1, y2);
	}

	const int dx = x2 - x1;
	const int dy = abs(y2 - y1);

	int e = dx / 2;
	const int stepY = (y1 < y2) ? 1 : -1;
	int y = y1;

	for(int x = x1; x <= x2; ++x)
	{
		if(step) setPixelSafe(cor, y, x);
		else setPixelSafe(cor, x, y);

		e -= dy;
		if(e < 0)
		{
			y += stepY;
			e += dx;
		}
	}
}
// =========================================================================================
void Image::clear( pixel bg )
{
#if	0
	const int pixelCount = width*height;

	for( int i=0; i<pixelCount ; i++ )
		buffer[i] = bg;
		
#else
	pixel* theEnd = buffer + width*height;
	pixel* it     = buffer;
	
	while( it != theEnd )
	{
		*it++ = bg;
	}
#endif
}
// =========================================================================================
int Image::getWidth() const
{
	return width;
}
// =========================================================================================
int Image::getHeight() const
{
	return height;
}
// =========================================================================================
int Image::getPixelCount() const
{
	return width*height;
}
// =========================================================================================
pixel* Image::getPixels()
{
	return buffer;
}
// =========================================================================================
const pixel* Image::getPixels() const
{
	return buffer;
}
// =========================================================================================	
void Image::display() const
{
	const float pw = 2.0f / (float) width;
	const float ph = 2.0f / (float) height;
	// coordenada Y do pixel na tela
	float py = 1.0f -ph;
	
	// itera por linha
	glBegin(GL_QUADS);
		for( int y=0 ; y<height ; ++y, py-=ph )
		{
			float px = -1.0;
				
			// varre cada pixel daquela linha
			for( int x=0 ; x<width ; ++x, px+=pw )
			{
				unsigned char uc = (unsigned char) pixels[y][x];
				const float gray = uc/255.0f;
			
			
					glColor3f( gray, gray, gray );
				
					glVertex2f( px   , py    );
					glVertex2f( px+pw, py    );
					glVertex2f( px+pw, py+ph );
					glVertex2f( px   , py+ph );			
			}
		}
	glEnd();
	
	// grade:
	glColor3f(0,0,0);
	glBegin(GL_LINES);
		py = 1.0f;
		for( int y=0 ; y<=height ; ++y, py-=ph )
		{
			glVertex2f(-1, py );
			glVertex2f(+1, py );
		}
		float px = 1.0f;
		for( int x=0 ; x<=width ; ++x, px-=pw )
		{
			glVertex2f( px,-1 );
			glVertex2f( px,+1 );
		}
	
	glEnd();
}
// =========================================================================================
void Image::setPixel( pixel cor, int i, int j )
{
	pixels[j][i] = cor;
}
// =========================================================================================
void Image::setPixelSafe( pixel cor, int i, int j )
{
	if( i >-1 && i<width && j>-1 && j<height )
		pixels[j][i] = cor;
}
// =========================================================================================
pixel Image::getPixel( int i, int j ) const
{
	return pixels[j][i];
}
// =========================================================================================
pixel Image::getPixelSafe( int i, int j ) const
{
	if( i >-1 && i<width && j>-1 && j<height )
		return pixels[j][i];
	
	return (pixel)0;
}
// =========================================================================================

