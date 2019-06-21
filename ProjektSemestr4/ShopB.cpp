#include "pch.h"
#include "ShopB.h"

ShopB::ShopB()
{
	int Bx = 260, By = 120;
	int lx = 20;

	int winX = 240, winY = 60;
	int winH = 600, winW = 800;
	int crossWH = 30;

	win = new Image("Obrazki/Window.jpg", winX, winY, winH, winW);
	cross = new Image(crossImageString, winX+winW-crossWH, winY, crossWH, crossWH);

	dSF = new Image(dragonScaleForgeImageString, Bx, By, buildingH, buildingW);
	pFA = new Image(phoenixFeatherAlchemistImageString, Bx + lx +buildingW, By, buildingH, buildingW);
	pFS = new Image(perytonFeatherSpecialistImageString, Bx + 2*lx + 2*buildingW, By, buildingH, buildingW);
}

ShopB::~ShopB()
{

	delete win;
	delete cross;
	delete dSF;
	delete pFA;
	delete pFS;

}

void ShopB::checkForInteraction(ALL_things * all_things, Game* game, Image* imag)
{
	all_things->waitForEvent();
	all_things->refreshMouseState();

	if (all_things->getMouseButtons() == 1) {
		if (all_things->getMouseY() > cross->getY() && all_things->getMouseY() < cross->getY() + cross->getH()) {
			if (all_things->getMouseX() > cross->getX() && all_things->getMouseX() < cross->getX() + cross->getW()) {
				quit = 1;
				return;
			}
		}

		if (all_things->getMouseY() > dSF->getY() && all_things->getMouseY() < dSF->getY() + dSF->getH()) {
			if (all_things->getMouseX() > dSF->getX() && all_things->getMouseX() < dSF->getX() + dSF->getW()) {
				if (game->getMoney() >= priceDragonScaleForge){
					game->setMoney(game->getMoney() - priceDragonScaleForge);
					game->addDragonScaleForge(new DragonScaleForge(imag->getX(), imag->getY()));
					game->deleteFreePlace(imag);
				}
				quit = 1;
				return;
			}
		}

		if (all_things->getMouseY() > pFA->getY() && all_things->getMouseY() < pFA->getY() + pFA->getH()) {
			if (all_things->getMouseX() > pFA->getX() && all_things->getMouseX() < pFA->getX() + pFA->getW()) {
				if (game->getMoney() >= pricePhoenixFeatherAlchemist) {
					game->setMoney(game->getMoney() - pricePhoenixFeatherAlchemist);
					game->addPhoenixFeatherAlchemist(new PhoenixFeatherAlchemist(imag->getX(), imag->getY()));
					game->deleteFreePlace(imag);
				}
				quit = 1;
				return;
			}
		}
	
		if (all_things->getMouseY() > pFS->getY() && all_things->getMouseY() < pFS->getY() + pFS->getH()) {
			if (all_things->getMouseX() > pFS->getX() && all_things->getMouseX() < pFS->getX() + pFS->getW()) {
				if (game->getMoney() >= pricePerytonFeatherSpecialist) {
					game->setMoney(game->getMoney() - pricePerytonFeatherSpecialist);
					game->addPerytonFeatherSpecialist(new PerytonFeatherSpecialist(imag->getX(), imag->getY()));
					game->deleteFreePlace(imag);
				}
				quit = 1;
				return;
			}
		}
	}
}

void ShopB::showShop(ALL_things* all_things)
{
	all_things->drawImage(win);
	all_things->drawImage(cross);
	all_things->drawImage(dSF);
	all_things->drawImage(pFA);
	all_things->drawImage(pFS);

	all_things->refreshDisplay();
}

void ShopB::shopLoop(ALL_things * all_things, Game* game, Image* imag)
{
	quit = 0;
	showShop(all_things);
	al_rest(0.5);

	while (quit == 0) {
		checkForInteraction(all_things, game, imag);
	}
	al_rest(0.3);
}
