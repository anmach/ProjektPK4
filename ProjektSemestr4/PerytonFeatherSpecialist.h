#pragma once
#include "Building.h"
#define pricePerytonFeatherSpecialist 200
#define defaultPerytonFeatherSpecialistProductionTime 50

class PerytonFeatherSpecialist :
	public Building
{
public:
	PerytonFeatherSpecialist();
	PerytonFeatherSpecialist(int x, int y);
	~PerytonFeatherSpecialist();

	void createStock(Game* game);
	void action(Game* game);
};

