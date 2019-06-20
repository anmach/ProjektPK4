#include "pch.h"
#include "Game.h"

Game::Game(ALL_things* all_things): all_things(all_things)
{
	menu = new Menu();
	shopBuild = new ShopB();
	shopAnimal = new Shop();
	bar = new Bar();
	level = new Level();

	background = al_load_bitmap("Obrazki/Background.jpg");

	for (int i = 1; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			freePlace.push_back(new Image("Obrazki/Buy.jpg", windowW - i * buildingH, farmY + j * buildingW, buildingH, buildingW));
		}
	}

	addPhoenix(new Phoenix(farmX, farmY));
}

Game::~Game()
{
	if (chosenPlace != nullptr)
		delete chosenPlace;

	delete menu;
	delete shopBuild;
	delete shopAnimal;
	delete bar;
	delete level;
	if(predator!= nullptr)
		delete predator;

	al_destroy_bitmap(background);

	for (std::list<Image*>::iterator itfreePla = freePlace.begin(); itfreePla != freePlace.end(); ++itfreePla)
	{
		delete (*itfreePla);
	}

	for (std::list<Dragon*>::iterator itDra = dragons.begin(); itDra != dragons.end(); ++itDra){
		delete (*itDra);
	}
	for (std::list<Peryton*>::iterator itPer = perytons.begin(); itPer != perytons.end(); ++itPer){
		delete(*itPer);
	}
	for (std::list<Phoenix*>::iterator itPho = phoenixes.begin(); itPho != phoenixes.end(); ++itPho){
		delete (*itPho);
	}

	for (std::list<DragonScale*>::iterator itDra = dragonScales.begin(); itDra != dragonScales.end(); ++itDra){
		delete (*itDra);
	}
	for (std::list<PerytonFeather*>::iterator itPer = perytonFeathers.begin(); itPer != perytonFeathers.end(); ++itPer){
		delete(*itPer);
	}
	for (std::list<PhoenixFeather*>::iterator itPho = phoenixFeathers.begin(); itPho != phoenixFeathers.end(); ++itPho){
		delete (*itPho);
	}

	for (std::list<DragonScaleForge*>::iterator itDraScaFo = dragonScalesForges.begin(); itDraScaFo != dragonScalesForges.end(); ++itDraScaFo){
		delete (*itDraScaFo);
	}
	for (std::list<PerytonFeatherSpecialist*>::iterator itPer = perytonFeatherSpecialists.begin(); itPer != perytonFeatherSpecialists.end(); ++itPer) {
		delete(*itPer);
	}
	for (std::list<PhoenixFeatherAlchemist*>::iterator itPho = phoenixFeatherAlchemists.begin(); itPho != phoenixFeatherAlchemists.end(); ++itPho) {
		delete (*itPho);
	}

}

#pragma region accesors
int Game::getMoney()
{
	return money;
}

int Game::getNoDraScales()
{
	return draScales;
}

int Game::getNoPerFeathers()
{
	return perFeathers;
}

int Game::getNoPhoFeathers()
{
	return phoFeathers;
}

int Game::getNoDraScales2()
{
	return draScales2;
}

int Game::getNoPerFeathers2()
{
	return perFeathers2;
}

int Game::getNoPhoFeathers2()
{
	return phoFeathers2;
}

int Game::getFood()
{
	return food;
}

bool Game::getRefreshGame()
{
	return refreshGame;
}

bool Game::getWonGame()
{
	return wonGame;
}

void Game::decreaseFood()
{
	food--;
}

void Game::decreasePerFeathers()
{
	perFeathers--;
}

void Game::decreasePhoFeathers()
{
	phoFeathers--;
}

void Game::decreaseDraScales()
{
	draScales--;
}

void Game::setDeadLock(bool se)
{
	deadLock = se;
}

void Game::setGameState(int st)
{
	gameState = st;
}

void Game::setMoney(int mo)
{
	money = mo;
}

void Game::setFood(int fd)
{
	food = fd;
}

void Game::setGivePredator(bool give)
{
	givePredator = give;
}

void Game::setNoDraScales(int no)
{
	if (no > draScales)
		level->setNoOfDragonScales(level->getNoOfDragonScales() + 1);
	draScales = no;
}

void Game::setNoPerFeathers(int no)
{
	if (no > perFeathers)
		level->setNoOfPerytonFeathers(level->getNoOfPerytonFeathers() + 1);
	perFeathers = no;
}

void Game::setNoPhoFeathers(int no)
{
	if (no > phoFeathers)
		level->setNoOfPhoenixFeathers(level->getNoOfPhoenixFeathers() + 1);
	phoFeathers = no;
}

void Game::setNoDraScales2(int no)
{
	if (no > draScales2)
		level->setNoOfDragonScales2(level->getNoOfDragonScales2() + 1);
	draScales2 = no;
}

void Game::setNoPerFeathers2(int no)
{
	if (no > perFeathers2)
		level->setNoOfPerytonFeathers2(level->getNoOfPerytonFeathers2() + 1);
	perFeathers2 = no;
}

void Game::setNoPhoFeathers2(int no)
{
	if (no > phoFeathers2)
		level->setNoOfPhoenixFeathers2(level->getNoOfPhoenixFeathers2() + 1);
	phoFeathers2 = no;
}

void Game::doRefreshGame()
{
	refreshGame = 1;
}
#pragma endregion

#pragma region add and kill
void Game::addDragon( Dragon* dragon)
{
	dragons.push_back(dragon);
	level->setNoOfDragons(level->getNoOfDragons() + 1);
}

void Game::addPeryton( Peryton* peryt)
{
	perytons.push_back(peryt);
	level->setNoOfPerytons(level->getNoOfPerytons() + 1);
}

void Game::addPhoenix(Phoenix* phoen)
{
	phoenixes.push_back(phoen);
	level->setNoOfPhoenixes(level->getNoOfPhoenixes() + 1);
}

void Game::addPredator()
{
	predator = new Predator();
	givePredator = 0;
}

void Game::killDragon(Dragon * dragon)
{
	for (auto itDra = dragons.begin(); itDra != dragons.end(); ++itDra){
		if (*itDra == dragon) {
			dragons.erase(itDra);
			delete dragon;
			break;
		}
	}
}

bool Game::killDragonIfCan()
{
	auto iter = dragons.begin();
	if (iter != dragons.end()) {
		killDragon((*iter));
		return true;
	}
	else
		return false;
}

void Game::killPhoenix(Phoenix * phoenix)
{
	for (auto itPho = phoenixes.begin(); itPho != phoenixes.end(); ++itPho) {
		if (*itPho == phoenix) {
			phoenixes.erase(itPho);
			delete phoenix;
			break;
		}
	}
}

bool Game::killPhoenixIfCan()
{

	auto iter = phoenixes.begin();
	if (iter != phoenixes.end()) {
		killPhoenix((*iter));
		return true;
	}
	else
		return false;
}

void Game::killPeryton(Peryton * peryton)
{
	for (auto itPer = perytons.begin(); itPer != perytons.end(); ++itPer) {
		if (*itPer == peryton) {
			perytons.erase(itPer);
			delete peryton;
			break;
		}
	}
}

bool Game::killPerytonIfCan()
{

	auto iter = perytons.begin();
	if (iter != perytons.end()) {
		killPeryton((*iter));
		return true;
	}
	else
		return false;
}

void Game::killPredator()
{
	delete predator;
	predator = nullptr;
}

void Game::addDragonScale( DragonScale* drSc)
{
	dragonScales.push_back(drSc);
}

void Game::addPhoenixFeather(PhoenixFeather* phFe)
{
	phoenixFeathers.push_back(phFe);
}

void Game::addPerytonFeather(PerytonFeather* peFe)
{
	perytonFeathers.push_back(peFe);
}

void Game::addDragonScaleForge(DragonScaleForge* drScFo)
{
	dragonScalesForges.push_back(drScFo);
	level->setNoOfDragonScaleForges(level->getNoOfDragonScaleForges() + 1);
}
void Game::addPhoenixFeatherAlchemist(PhoenixFeatherAlchemist * PhoFeAl)
{
	phoenixFeatherAlchemists.push_back(PhoFeAl);
	level->setNoOfPhoenixFeatherAlchemists(level->getNoOfPhoenixFeatherAlchemists() + 1);
}
void Game::addPerytonFeatherSpecialist(PerytonFeatherSpecialist * PerFeSp)
{
	perytonFeatherSpecialists.push_back(PerFeSp);
	level->setNoOfPerytonFeatherSpecialists(level->getNoOfPerytonFeatherSpecialists() + 1);
}
void Game::deleteFreePlace(Image * imag)
{
	for (auto itFree = freePlace.begin(); itFree != freePlace.end(); ++itFree) {
		if (*itFree == imag) {
			freePlace.erase(itFree);
			delete imag;
			break;
		}
	}
}
#pragma endregion

Animal * Game::findNearestAnimal(int animalX, int animalY, std::string&type)
{
	int nearest = farmW ^ 2 + farmH ^ 2;
	int checked = 0;
	Animal* found = nullptr;

	for (std::list<Dragon*>::iterator itDra = dragons.begin(); itDra != dragons.end(); ++itDra) {
		checked = ((*itDra)->getImg()->getX()) ^ 2 + ((*itDra)->getImg()->getY()) ^ 2;
		if (checked < nearest) {
			nearest = checked;
			found = (*itDra);
			type = "dragon";
		}
	}

	for (std::list<Peryton*>::iterator itPer = perytons.begin(); itPer != perytons.end(); ++itPer) {
		checked = ((*itPer)->getImg()->getX()) ^ 2 + ((*itPer)->getImg()->getY()) ^ 2;
		if (checked < nearest) {
			nearest = checked;
			found = (*itPer);
			type = "peryton";
		}
	}

	for (std::list<Phoenix*>::iterator itPho = phoenixes.begin(); itPho != phoenixes.end(); ++itPho) {
		checked = ((*itPho)->getImg()->getX()) ^ 2 + ((*itPho)->getImg()->getY()) ^ 2;
		if (checked < nearest) {
			nearest = checked;
			found = (*itPho);
			type = "phoenix";
		}
	}

	return found;
}

void Game::gameLoop()
{
	clock_t lastTime = clock();
	clock_t actualTime = clock();

	std::thread t1;
	std::thread t2;

	while(gameState == justPlaying){
		while ((actualTime - lastTime) < 300)
			actualTime = clock();

		lastTime = actualTime;

		all_things->drawBackground(background);
		showAnimal();
		showBuildings();
		showStock();
		showPredator();
		bar->showBar(all_things, this);
		all_things->refreshDisplay();

		t1 = std::thread(&Game::gameLoop_actions, this);
		t2 = std::thread(&Game::checkForInteraction, this);

		t1.join();
		t2.join();

		if (!deadLock) {
			switch (gameState)
			{
			case shoppingAnimal:
				shopAnimal->shopLoop(all_things, this);
				deadLock = 1;
				gameState = justPlaying;
				break;
			case shoppingBuilding:
				shopBuild->shopLoop(all_things, this, chosenPlace);
				deadLock = 1;
				gameState = justPlaying;
				break;
			case wantMenu:
				menu->menuLoop(all_things, this);
				break;
			default:
				break;
			}
		}

		if (level->levelPassed()) {
			wonGame = 1;
			gameState = endingGame;
		}
	}
}

void Game::gameLoop_actions()
{
	animalActions();
	buildingActions();
	predatorActions();
}

void Game::animalActions()
{
	for (std::list<Dragon*>::iterator itDra = dragons.begin(); itDra != dragons.end();)	{
		(*itDra++)->action(this);
	}

	for (std::list<Peryton*>::iterator itPer = perytons.begin(); itPer != perytons.end();) {
		(*itPer++)->action(this);
	}

	for (std::list<Phoenix*>::iterator itPho = phoenixes.begin(); itPho != phoenixes.end();) {
		(*itPho++)->action(this);
	}
}

void Game::showAnimal()
{
	for (std::list<Dragon*>::iterator itDra = dragons.begin(); itDra != dragons.end();itDra++) {

		all_things->drawImage((*itDra)->getImg());
	}

	for (std::list<Peryton*>::iterator itPer = perytons.begin(); itPer != perytons.end();itPer++) {
		all_things->drawImage((*itPer)->getImg());
	}

	for (std::list<Phoenix*>::iterator itPho = phoenixes.begin(); itPho != phoenixes.end();itPho++) {
		all_things->drawImage((*itPho)->getImg());
	}
}

void Game::buildingActions()
{
	for (std::list<DragonScaleForge*>::iterator itDra = dragonScalesForges.begin(); itDra != dragonScalesForges.end();) {
		(*itDra++)->action(this);
	}

	for (std::list<PerytonFeatherSpecialist*>::iterator itPer = perytonFeatherSpecialists.begin(); itPer != perytonFeatherSpecialists.end();) {
		(*itPer++)->action(this);
	}

	for (std::list<PhoenixFeatherAlchemist*>::iterator itPho = phoenixFeatherAlchemists.begin(); itPho != phoenixFeatherAlchemists.end();) {
		(*itPho++)->action(this);
	}
}

void Game::showBuildings()
{
	for (std::list<Image*>::iterator itfreePla = freePlace.begin(); itfreePla != freePlace.end(); ++itfreePla) {
		all_things->drawImage(*itfreePla);
	}

	for (std::list<DragonScaleForge*>::iterator itDra = dragonScalesForges.begin(); itDra != dragonScalesForges.end(); itDra++) {
		all_things->drawImage((*itDra)->getImg());
		if ((*itDra)->getProduce())
			all_things->drawRectangleOnImage((*itDra)->getImg());
	}

	for (std::list<PerytonFeatherSpecialist*>::iterator itPer = perytonFeatherSpecialists.begin(); itPer != perytonFeatherSpecialists.end();itPer++) {
		all_things->drawImage((*itPer)->getImg());
		if ((*itPer)->getProduce())
			all_things->drawRectangleOnImage((*itPer)->getImg());
	}

	for (std::list<PhoenixFeatherAlchemist*>::iterator itPho = phoenixFeatherAlchemists.begin(); itPho != phoenixFeatherAlchemists.end();itPho++) {
		all_things->drawImage((*itPho)->getImg());
		if ((*itPho)->getProduce())
			all_things->drawRectangleOnImage((*itPho)->getImg());
	}
}

void Game::predatorActions()
{
	if (predator != nullptr) {
		predator->hunt(this);
		if (predator != nullptr)
			predator->hunt(this);
		if (predator != nullptr)
			predator->hunt(this);
	}
	else if (givePredator)
			addPredator();
}

void Game::showPredator()
{
	if (predator != nullptr) {
		all_things->drawImage(predator->getImg());
	}
}

void Game::showStock()
{
	for (std::list<DragonScale*>::iterator itDraSca = dragonScales.begin(); itDraSca != dragonScales.end(); ++itDraSca)
	{
		all_things->drawImage((*itDraSca)->getImg());
	}
	
	for (std::list<PhoenixFeather*>::iterator itPhoFea = phoenixFeathers.begin(); itPhoFea != phoenixFeathers.end(); ++itPhoFea)
	{
		all_things->drawImage((*itPhoFea)->getImg());
	}

	for (std::list<PerytonFeather*>::iterator itPerFea = perytonFeathers.begin(); itPerFea != perytonFeathers.end(); ++itPerFea)
	{
		all_things->drawImage((*itPerFea)->getImg());
	}
}

void Game::checkForInteraction()
{
	while (all_things->nextEvent())
	{
		all_things->refreshMouseState();

		if (all_things->getMouseButtons() == 1) {
			//naciœniêty lewy klawisz myszy

			for (std::list<DragonScale*>::iterator itDraSca = dragonScales.begin(); itDraSca != dragonScales.end(); ++itDraSca)
			{
				if (all_things->getMouseY() > (*itDraSca)->getImg()->getY() && all_things->getMouseY() < (*itDraSca)->getImg()->getY() + (*itDraSca)->getImg()->getH())
				{
					if (all_things->getMouseX() > (*itDraSca)->getImg()->getX() && all_things->getMouseX() < (*itDraSca)->getImg()->getX() + (*itDraSca)->getImg()->getW())
					{
						DragonScale* usuwany = *itDraSca;
						draScales++;
						dragonScales.remove(usuwany);
						delete usuwany;
						return;
					}
				}
			}

			for (std::list<PhoenixFeather*>::iterator itPhoFea = phoenixFeathers.begin(); itPhoFea != phoenixFeathers.end(); ++itPhoFea)
			{
				if (all_things->getMouseY() > (*itPhoFea)->getImg()->getY() && all_things->getMouseY() < (*itPhoFea)->getImg()->getY() + (*itPhoFea)->getImg()->getH())
				{
					if (all_things->getMouseX() > (*itPhoFea)->getImg()->getX() && all_things->getMouseX() < (*itPhoFea)->getImg()->getX() + (*itPhoFea)->getImg()->getW())
					{
						PhoenixFeather* usuwany = *itPhoFea;
						phoFeathers++;
						phoenixFeathers.remove(usuwany);
						delete usuwany;
						return;
					}
				}

			}

			for (std::list<PerytonFeather*>::iterator itPerFea = perytonFeathers.begin(); itPerFea != perytonFeathers.end(); ++itPerFea)
			{
				if (all_things->getMouseY() > (*itPerFea)->getImg()->getY() && all_things->getMouseY() < (*itPerFea)->getImg()->getY() + (*itPerFea)->getImg()->getH())
				{
					if (all_things->getMouseX() > (*itPerFea)->getImg()->getX() && all_things->getMouseX() < (*itPerFea)->getImg()->getX() + (*itPerFea)->getImg()->getW())
					{
						PerytonFeather* usuwany = *itPerFea;
						perFeathers++;
						perytonFeathers.remove(usuwany);
						delete usuwany;
						return;
					}
				}

			}

			for (std::list<DragonScaleForge*>::iterator itDr = dragonScalesForges.begin(); itDr != dragonScalesForges.end(); ++itDr)
			{
				if (all_things->getMouseY() > (*itDr)->getImg()->getY() && all_things->getMouseY() < (*itDr)->getImg()->getY() + (*itDr)->getImg()->getH())
				{
					if (all_things->getMouseX() > (*itDr)->getImg()->getX() && all_things->getMouseX() < (*itDr)->getImg()->getX() + (*itDr)->getImg()->getW())
					{
						(*itDr)->setProduce(1);
						return;
					}
				}
			}

			for (std::list<PhoenixFeatherAlchemist*>::iterator itDr = phoenixFeatherAlchemists.begin(); itDr != phoenixFeatherAlchemists.end(); ++itDr)
			{
				if (all_things->getMouseY() > (*itDr)->getImg()->getY() && all_things->getMouseY() < (*itDr)->getImg()->getY() + (*itDr)->getImg()->getH())
				{
					if (all_things->getMouseX() > (*itDr)->getImg()->getX() && all_things->getMouseX() < (*itDr)->getImg()->getX() + (*itDr)->getImg()->getW())
					{
						(*itDr)->setProduce(1);
						return;
					}
				}
			}

			for (std::list<PerytonFeatherSpecialist*>::iterator itDr = perytonFeatherSpecialists.begin(); itDr != perytonFeatherSpecialists.end(); ++itDr)
			{
				if (all_things->getMouseY() > (*itDr)->getImg()->getY() && all_things->getMouseY() < (*itDr)->getImg()->getY() + (*itDr)->getImg()->getH())
				{
					if (all_things->getMouseX() > (*itDr)->getImg()->getX() && all_things->getMouseX() < (*itDr)->getImg()->getX() + (*itDr)->getImg()->getW())
					{
						(*itDr)->setProduce(1);
						return;
					}
				}
			}

			//Otwieramy sklep z budynkami
			for (std::list<Image*>::iterator itFreePla = freePlace.begin(); itFreePla != freePlace.end(); ++itFreePla)
			{
				if (all_things->getMouseY() > (*itFreePla)->getY() && all_things->getMouseY() < (*itFreePla)->getY() + (*itFreePla)->getH())
				{
					if (all_things->getMouseX() > (*itFreePla)->getX() && all_things->getMouseX() < (*itFreePla)->getX() + (*itFreePla)->getW())
					{
						gameState = shoppingBuilding;
						deadLock = 0;
						chosenPlace = *itFreePla;
						return;
					}
				}
			}

			if (predator != nullptr) {
				if (all_things->getMouseY() > predator->getImg()->getY() && all_things->getMouseY() < predator->getImg()->getY() + predator->getImg()->getH())
				{
					if (all_things->getMouseX() > predator->getImg()->getX() && all_things->getMouseX() < predator->getImg()->getX() + predator->getImg()->getW())
					{
						if (!(rand() % 3))
							killPredator();
						return;
					}
				}
			}

			bar->checkForInteraction(all_things, this);
		}
	}
}



