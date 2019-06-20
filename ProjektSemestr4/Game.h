#pragma once
#include "Shop.h"
#include "ShopB.h"
#include "Bar.h"
#include "Predator.h"
#include "Level.h"
#include <thread>

#include <time.h>

class Animal;
class Dragon;
class Peryton;
class Phoenix;
class PhoenixFeather;
class PerytonFeather;
class DragonScale;
class DragonScaleForge;
class PhoenixFeatherAlchemist;
class PerytonFeatherSpecialist;

enum statesOfGame { shoppingAnimal, shoppingBuilding, wantMenu, justPlaying, endingGame };


class Game
{
	//animals, buildings, stock in game
private:
	Menu* menu;
	Level* level;
	ALLEGRO_BITMAP* background = nullptr;
	ALL_things* all_things = nullptr;

	std::list<Image*> freePlace;
	Image* chosenPlace = nullptr;

	std::list <Dragon*> dragons;
	std::list <Peryton*> perytons;
	std::list <Phoenix*> phoenixes;

	std::list <DragonScale*> dragonScales;
	std::list <PhoenixFeather*> phoenixFeathers;
	std::list <PerytonFeather*> perytonFeathers;

	std::list <DragonScaleForge*> dragonScalesForges;
	std::list <PhoenixFeatherAlchemist*> phoenixFeatherAlchemists;
	std::list <PerytonFeatherSpecialist*> perytonFeatherSpecialists;

	ShopB* shopBuild = nullptr;
	Shop* shopAnimal = nullptr;
	Bar* bar = nullptr;

	int draScales = 0;
	int phoFeathers = 0;
	int perFeathers = 0;

	int draScales2 = 0;
	int phoFeathers2 = 0;
	int perFeathers2 = 0;

	int food = 0;
	int money = 2000;

	Predator* predator = nullptr;
	bool givePredator = 0;

	bool refreshGame = 0;
	bool deadLock = 1;
	int gameState = justPlaying;
	bool wonGame = 0;

public:
	Game(ALL_things* all_things);
	~Game();
	
	int getMoney();
	int getNoDraScales();
	int getNoPerFeathers();
	int getNoPhoFeathers();
	int getNoDraScales2();
	int getNoPerFeathers2();
	int getNoPhoFeathers2();
	int getFood();
	bool getRefreshGame();
	bool getWonGame();

	void decreaseFood();
	void decreasePerFeathers();
	void decreasePhoFeathers();
	void decreaseDraScales();

	void setDeadLock(bool se);
	void setGameState(int st);
	void setMoney(int mo);
	void setFood(int fd);
	void setGivePredator(bool give);
	void setNoDraScales(int no);
	void setNoPerFeathers(int no);
	void setNoPhoFeathers(int no);
	void setNoDraScales2(int no);
	void setNoPerFeathers2(int no);
	void setNoPhoFeathers2(int no);

	void doRefreshGame();

#pragma region add and kill
	void addDragon(Dragon* dragon);
	void addPeryton(Peryton* peryt);
	void addPhoenix(Phoenix* phoen);
	void addPredator();

	void killDragon(Dragon* dragon);
	bool killDragonIfCan();
	void killPhoenix(Phoenix* phoenix);
	bool killPhoenixIfCan();
	void killPeryton(Peryton* peryton);
	bool killPerytonIfCan();
	void killPredator();

	void addDragonScale(DragonScale* dragonSca);
	void addPhoenixFeather(PhoenixFeather* phoenixFea);
	void addPerytonFeather(PerytonFeather* peFe);

	void addDragonScaleForge(DragonScaleForge* DragonScaleFor);
	void addPhoenixFeatherAlchemist(PhoenixFeatherAlchemist* PhoFeAl);
	void addPerytonFeatherSpecialist(PerytonFeatherSpecialist* PerFeSp);

	void deleteFreePlace(Image* imag);
#pragma endregion

	Animal* findNearestAnimal(int animalX, int animalY, std::string&type);

	void gameLoop();
	void gameLoop_actions();
	void animalActions();
	void showAnimal();
	void buildingActions();
	void showBuildings();
	void predatorActions();
	void showPredator();
	void showStock();

	void checkForInteraction();
};