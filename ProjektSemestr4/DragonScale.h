#pragma once
#include "Stock.h"
#define priceDragonScale 100

class DragonScale :
	public Stock
{
public:
	DragonScale();
	DragonScale(int x, int y);
	~DragonScale();
};

