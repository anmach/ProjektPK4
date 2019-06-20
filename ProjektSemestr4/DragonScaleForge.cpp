#include "pch.h"
#include "DragonScaleForge.h"


DragonScaleForge::DragonScaleForge() : Building("", 0, 0)
{}

DragonScaleForge::DragonScaleForge(int x, int y) : Building(dragonScaleForgeImageString, x, y)
{}


DragonScaleForge::~DragonScaleForge()
{
}

void DragonScaleForge::createStock(Game* game)
{
		game->setNoDraScales2(game->getNoDraScales2() + 1);
		setProdTime(0);
		setProduce(0);
}

void DragonScaleForge::action(Game * game)
{
	 if (getProduce()) {
		 if (getProdTime() == 0) {
			 if(game->getNoDraScales()>0){
				 game->decreaseDraScales();
				 setProdTime(defaultDragonScaleForgeProductionTime);
			 }
			 else
				 setProduce(0);
		}
		else if (getProdTime() == 1)
			createStock(game);
		else
			setProdTime(getProdTime()-1);
	}
}

