#pragma once
#include "Animal.h"
#define pricePeryton 100

class Peryton :
	public Animal
{
public:
	Peryton();
	Peryton(int x, int y);
	~Peryton();

	void makeStock(Game* game);
	void action(Game* game);
};

