#include "pch.h"
#include "Level.h"


Level::Level()
{
}


Level::~Level()
{
}

int Level::getNoOfDragons()
{
	return noOfDragons;
}

int Level::getNoOfPhoenixes()
{
	return noOfPhoenixes;
}

int Level::getNoOfPerytons()
{
	return noOfPerytons;
}

int Level::getNoOfDragonScales()
{
	return noOfDragonScales;
}

int Level::getNoOfPhoenixFeathers()
{
	return noOfPhoenixFeathers;
}

int Level::getNoOfPerytonFeathers()
{
	return noOfPerytonFeathers;
}

int Level::getNoOfDragonScales2()
{
	return noOfDragonScales2;
}

int Level::getNoOfPhoenixFeathers2()
{
	return noOfPhoenixFeathers2;
}

int Level::getNoOfPerytonFeathers2()
{
	return noOfPerytonFeathers2;
}

int Level::getNoOfDragonScaleForges()
{
	return noOfDragonScaleForgess;
}

int Level::getNoOfPhoenixFeatherAlchemists()
{
	return noOfPhoenixFeatherAlchemists;
}

int Level::getNoOfPerytonFeatherSpecialists()
{
	return noOfPerytonFeatherSpecialists;
}

void Level::setNoOfDragons(int x)
{
	noOfDragons = x;
}

void Level::setNoOfPhoenixes(int x)
{
	noOfPhoenixes = x;
}

void Level::setNoOfPerytons(int x)
{
	noOfPerytons = x;
}

void Level::setNoOfDragonScales(int x)
{
	noOfDragonScales = x;
}

void Level::setNoOfPhoenixFeathers(int x)
{
	noOfPhoenixFeathers = x;
}

void Level::setNoOfPerytonFeathers(int x)
{
	noOfPerytonFeathers = x;
}

void Level::setNoOfDragonScales2(int x)
{
	noOfDragonScales2 = x;
}

void Level::setNoOfPhoenixFeathers2(int x)
{
	noOfPhoenixFeathers2 = x;
}

void Level::setNoOfPerytonFeathers2(int x)
{
	noOfPerytonFeathers2 = x;
}

void Level::setNoOfDragonScaleForges(int x)
{
	noOfDragonScaleForgess = x;
}

void Level::setNoOfPhoenixFeatherAlchemists(int x)
{
	noOfPhoenixFeatherAlchemists = x;
}

void Level::setNoOfPerytonFeatherSpecialists(int x)
{
	noOfPerytonFeatherSpecialists = x;
}

bool Level::levelPassed()
{
	if (levelNoOfDragons <= noOfDragons && levelNoOfPhoenixes <= noOfPhoenixes && levelNoOfPerytons <= noOfPerytons)
		if (levelNoOfDragonScales <= noOfDragonScales && levelNoOfPhoenixFeathers <= noOfPhoenixFeathers && levelNoOfPerytonFeathers <= noOfPerytonFeathers)
			if (levelNoOfDragonScales2 <= noOfDragonScales2 && levelNoOfPhoenixFeathers2 <= noOfPhoenixFeathers2 && levelNoOfPerytonFeathers2 <= noOfPerytonFeathers2)
				if (levelNoOfDragonScaleForgess <= noOfDragonScaleForgess && levelNoOfPhoenixFeatherAlchemists <= noOfPhoenixFeatherAlchemists && levelNoOfPerytonFeatherSpecialists <= noOfPerytonFeatherSpecialists)
					return true;
	return false;
}	  
 