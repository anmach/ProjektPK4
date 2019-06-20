#include "pch.h"
#include "Animal.h"

Animal::Animal(): Animal(0,"", 0,0,0,0)
{}

Animal::Animal(short pSell, std::string im, int x, int y, short proTime, short maxHun): priceSell(pSell), defaultProductionTime(proTime), maxHunger(maxHun)
{
	img = new Image(im, x, y, animalH, animalW);
	dx = std::rand() % 6 - 3;
	dy = std::rand() % 6 - 3;
	productionTime = defaultProductionTime;
}

Animal::~Animal()
{
	delete img;
}

#pragma region Accesors

short Animal::getHunger()
{
	return hunger;
}

short Animal::getMaxHunger()
{
	return maxHunger;
}

short Animal::getPriceSell()
{
	return priceSell;
}

Image* Animal::getImg()
{
	return img;
}

short Animal::getProductionTime()
{
	return productionTime;
}

short Animal::getDefaultProductionTime()
{
	return defaultProductionTime;
}

short Animal::getDx()
{
	return dx;
}

short Animal::getDy()
{
	return dy;
}

void Animal::setHunger(short newHunger)
{
	hunger = newHunger;
}

void Animal::setPriceSell(short price)
{
	priceSell = price;
}
void Animal::setImg(Image* imag)
{
	img = imag;
}
void Animal::setProductionTime(short x)
{
	productionTime = x;
}
#pragma endregion

void Animal::setDx(short x)
{
	dx = x;
}

void Animal::setDy(short x)
{
	dy = x;
}

void Animal::makeStock(Game* game)
{}

void Animal::walk()
{
	if (rand() % 100 > 95) {
		setDx(std::rand() % 6 - 3);
		setDy(std::rand() % 6 - 3);
	}

	if (getDx() == 0 && getDy() == 0)
		setDx(1);

	if (getImg()->getX() > (farmX + farmW) || getImg()->getX() < farmX) {
		setDx((-getDx()));
		img->setX(img->getX() + dx);
	}
	if (getImg()->getY() > (farmY + farmH) || getImg()->getY() < farmY) {
		setDy((-getDy()));
		img->setY(img->getY() + dy);
	}

	getImg()->setX(getImg()->getX() + getDx());
	getImg()->setY(getImg()->getY() + getDy());
}

void Animal::eat()
{
	hunger = 0;
}

void Animal::getMoreHunger()
{
	hunger+=1;
}

void Animal::shortenProductionTime(short x)
{
	productionTime -= x;
}

void Animal::action(Game* game)
{}
