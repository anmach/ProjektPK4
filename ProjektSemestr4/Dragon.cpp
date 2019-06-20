#include "pch.h"
#include "Dragon.h"

Dragon::Dragon(): Dragon(farmX, farmY)
{}

Dragon::Dragon(int x, int y):Animal(priceDragon/2, dragonImageString, x, y, 400, 100)
{}

Dragon::~Dragon()
{}

void Dragon::makeStock(Game* game)
{
	game->addDragonScale(new DragonScale(getImg()->getX(), getImg()->getY()));
}


void Dragon::action(Game* game)
{
	getMoreHunger();
	shortenProductionTime(rand() % 5);

	if (getHunger() > getMaxHunger()/2){
		if (getHunger() >= getMaxHunger()){
			//œmieræ
			game->killDragon(this);
		}
		else if (game->getFood() > 0){
			//jedzenie
			game->decreaseFood();
			setHunger(0);
		}
		else
			walk();
	}
	else if (getProductionTime() <= 0){
		//produkcja surowca
		makeStock(game); 
		setProductionTime(getDefaultProductionTime());
	}
	else
		walk();
		//chodzenie
}
