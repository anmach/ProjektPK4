#pragma once
#include "Animal.h"
#define priceDragon 400

class Dragon : public Animal
{
public:
	Dragon();
	Dragon(int x, int y);
	~Dragon();

	void makeStock(Game* game);
	void action(Game* game);
};