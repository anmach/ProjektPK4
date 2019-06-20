#pragma once
#include "Building.h"
#define priceDragonScaleForge 100 
#define defaultDragonScaleForgeProductionTime 60

class DragonScaleForge : public Building
{
public:
	DragonScaleForge();
	DragonScaleForge(int x, int y);
	~DragonScaleForge();

	void createStock(Game* game);
	void action(Game* game);
};

