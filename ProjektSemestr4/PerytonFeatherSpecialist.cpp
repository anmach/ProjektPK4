#include "pch.h"
#include "PerytonFeatherSpecialist.h"


PerytonFeatherSpecialist::PerytonFeatherSpecialist() : PerytonFeatherSpecialist(0, 0)
{
}

PerytonFeatherSpecialist::PerytonFeatherSpecialist(int x, int y) : Building(perytonFeatherSpecialistImageString, x, y)
{
}


PerytonFeatherSpecialist::~PerytonFeatherSpecialist()
{
}

void PerytonFeatherSpecialist::createStock(Game * game)
{
	game->setNoPerFeathers2(game->getNoPerFeathers2() + 1);
	setProdTime(0);
	setProduce(0);
}

void PerytonFeatherSpecialist::action(Game * game)
{
	if (getProduce()) {
		if (getProdTime() == 0) {
			if (game->getNoPerFeathers() > 0) {
				game->decreasePerFeathers();
				setProdTime(defaultPerytonFeatherSpecialistProductionTime);
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
