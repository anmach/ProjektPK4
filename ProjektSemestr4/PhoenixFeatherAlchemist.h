#pragma once
#include "Building.h"
#define pricePhoenixFeatherAlchemist 100 
#define defaultPhoenixFeatherAlchemistProductionTime 100

class PhoenixFeatherAlchemist :
	public Building
{
public:
	PhoenixFeatherAlchemist();
	PhoenixFeatherAlchemist(int x, int y);
	~PhoenixFeatherAlchemist();

	void createStock(Game* game);
	void action(Game* game);
};

