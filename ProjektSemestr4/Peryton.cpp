#include "pch.h"
#include "Peryton.h"


Peryton::Peryton() :Peryton(farmX, farmY)
{
}

Peryton::Peryton(int x, int y): Animal(pricePeryton/2, perytonImageString, x, y, 200, 200)
{
}


Peryton::~Peryton()
{
}

void Peryton::action(Game* game)
{
	getMoreHunger();
	shortenProductionTime(rand() % 5);

	if (getHunger() > getMaxHunger()/2) {
		if (getHunger() > getMaxHunger()) {
			//œmieræ
			game->killPeryton(this);
		}
		else if (game->getFood() > 0) {
			//jedzenie
			game->decreaseFood();
			setHunger(0);
		}
		else
			walk();
	}
	else if (getProductionTime() <= 0) {
		//produkcja surowca
		makeStock(game);
		setProductionTime(getDefaultProductionTime());
	}
	else
		walk();
	//chodzenie
}

void Peryton::makeStock(Game* game)
{
	game->addPerytonFeather(new PerytonFeather(getImg()->getX(), getImg()->getY()));
}
