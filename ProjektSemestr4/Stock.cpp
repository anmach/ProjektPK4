#include "pch.h"
#include "Stock.h"

Stock::Stock()
{
}

Stock::Stock(short time, std::string imag, int x,int y):timeProduction(time)
{
	img = new Image(imag, x, y, stockH, stockW);
}

Stock::~Stock()
{
	delete img;
}

short Stock::getTimeProduction()
{
	return timeProduction;
}

Image * Stock::getImg()
{
	return img;
}

void Stock::setTimeProduction(short time)
{
	timeProduction = time;
}

void Stock::setImg(Image * imag)
{
	img = imag;
}
