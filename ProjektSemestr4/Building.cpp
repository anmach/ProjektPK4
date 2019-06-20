#include "pch.h"
#include "Building.h"

Building::Building(): Building("", 0,0)
{
}

Building::Building(std::string im, int x, int y)
{
	img = new Image(im, x, y, buildingH, buildingW);
}

Building::~Building()
{
	delete img;
}

short Building::getNumberStock()
{
	return numberStock;
}

Image * Building::getImg()
{
	return img;
}

int Building::getProdTime()
{
	return prodTime;
}

bool Building::getProduce()
{
	return produce;
}

void Building::setNumberStock(short number)
{
	numberStock = number;
}

void Building::setImg(Image * imag)
{
	img = imag;
}

void Building::setProdTime(int ss)
{
	prodTime = ss;
}

void Building::setProduce(bool yn)
{
	produce = yn;
}

void Building::createStock(Game* game)
{
}

void Building::action(Game * game)
{
}
