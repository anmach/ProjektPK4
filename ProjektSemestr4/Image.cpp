#include "pch.h"
#include "Image.h"

Image::Image()
{
}

Image::Image(std::string imag, int x, int y, int h, int w): x(x), y(y), height(h), width(w)
{
	img = al_load_bitmap(imag.c_str());
}


Image::~Image()
{
	if (img != nullptr)
		al_destroy_bitmap(img);
}

ALLEGRO_BITMAP * Image::getImg()
{
	return img;
}

int Image::getX()
{
	return x;
}

int Image::getY()
{
	return y;
}

int Image::getH()
{
	return height;
}

int Image::getW()
{
	return width;
}

void Image::setX(int newX)
{
	x = newX;
}

void Image::setY(int newY)
{
	y = newY;
}
