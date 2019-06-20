#pragma once
#include "Animal.h"
#define pricePhoenix 200

class Phoenix :
	public Animal
{
public:
	Phoenix();
	Phoenix(int x, int y);
	~Phoenix();

	void makeStock(Game* game);
	void action(Game* game);
};