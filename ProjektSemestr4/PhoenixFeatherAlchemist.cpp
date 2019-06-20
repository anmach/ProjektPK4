#include "pch.h"
#include "PhoenixFeatherAlchemist.h"


PhoenixFeatherAlchemist::PhoenixFeatherAlchemist() : PhoenixFeatherAlchemist(0, 0)
{}

PhoenixFeatherAlchemist::PhoenixFeatherAlchemist(int x, int y) : Building(phoenixFeatherAlchemistImageString, x, y)
{}


PhoenixFeatherAlchemist::~PhoenixFeatherAlchemist()
{}

void PhoenixFeatherAlchemist::createStock(Game * game)
{
	game->setNoPhoFeathers2(game->getNoPhoFeathers2() + 1);
	setProdTime(0);
	setProduce(0);
}

void PhoenixFeatherAlchemist::action(Game * game)
{
	if (getProduce()) {
		if (getProdTime() == 0) {
			if (game->getNoPhoFeathers() > 0) {
				game->decreasePhoFeathers();
				setProdTime(defaultPhoenixFeatherAlchemistProductionTime);
			}
			else
				setProduce(0);
		}
		else if (getProdTime() == 1)
			createStock(game);
		else
			setProdTime(getProdTime() - 1);
	}
}
