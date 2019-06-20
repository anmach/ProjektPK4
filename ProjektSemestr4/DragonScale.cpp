#include "pch.h"
#include "DragonScale.h"


DragonScale::DragonScale(): DragonScale(0,0)
{}


DragonScale::DragonScale(int x, int y): Stock(priceDragonScale, dragonScaleImageString,x,y)
{
}

DragonScale::~DragonScale()
{
}
