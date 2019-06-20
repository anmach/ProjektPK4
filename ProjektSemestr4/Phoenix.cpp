#include "pch.h"
#include "Phoenix.h"


Phoenix::Phoenix(): Phoenix(farmX, farmY)
{}

Phoenix::Phoenix(int x, int y): Animal(pricePhoenix/2, phoenixImageString, x, y, 300, 300)
{}


Phoenix::~Phoenix()
{}

void Phoenix::makeStock(Game* game)
{
	game->addPhoenixFeather(new PhoenixFeather(getImg()->getX(), getImg()->getY()));
}

void Phoenix::action(Game* game)
{
	getMoreHunger();
	shortenProductionTime(rand() % 5);

	if (getHunger() > getMaxHunger()/2) {
		if (getHunger() > getMaxHunger()) {
			//œmieræ
			game->killPhoenix(this);
		}
		else if (game->getFood() > 0){
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
