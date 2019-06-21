#include "pch.h"
#include "Shop.h"


Shop::Shop()
{
	int distance = 100, firstX = 300;
	int positionY = 100;
	int winX = 240, winY = 60;
	int winW = 800, winH = 600;
	int win2W = 300, win2H = 300;
	int win2X = windowW / 2 - win2W / 2;
	int win2Y = windowH / 2 - win2H / 2;
	int butW = 144, butH = 100;
	int butX = win2X + win2W / 2 - butW / 2;
	int butY = win2Y + win2H / 3 - butH / 2;
	int butY2 = win2Y + 2*win2H / 3 - butH / 2;
	int crossWH = 30;

	win = new Image("Obrazki/Window.jpg", winX, winY, winH, winW);
	cross = new Image(crossImageString, winX+winW-crossWH, winY, crossWH, crossWH);

	win2 = new Image("Obrazki/ChoiceB.jpg", win2X, win2Y, win2H, win2W);
	buttonBuy = new Image("Obrazki/BuyButton.jpg", butX, butY, butH, butW);
	buttonSell = new Image("Obrazki/SellButton.jpg", butX, butY2, butH, butW);

	dra = new Image(dragonImageString, firstX, positionY, animalH, animalW);
	per = new Image(perytonImageString, firstX+ distance, positionY, animalH, animalW);
	pho = new Image(phoenixImageString, firstX+2* distance, positionY, animalH, animalW);

	drS = new Image(dragonScaleImageString, firstX, 2* positionY, stockH, stockW);
	peF = new Image(perytonFeatherImageString, firstX + distance, 2 * positionY, stockH, stockW);
	phF = new Image(phoenixFeatherImageString, firstX + 2 * distance, 2 * positionY, stockH, stockW);

	drS2 = new Image(dragonScale2ImageString, firstX, 3 * positionY, stockH, stockW);
	peF2 = new Image(perytonFeather2ImageString, firstX + distance, 3 * positionY, stockH, stockW);
	phF2 = new Image(phoenixFeather2ImageString, firstX + 2 * distance, 3 * positionY, stockH, stockW);
}					

Shop::~Shop()
{
	delete win;
	delete cross;

	delete win2;
	delete buttonBuy;
	delete buttonSell;

	delete	dra;
	delete	per;
	delete	pho;

	delete	drS;
	delete	peF;
	delete	phF;

	delete	drS2;
	delete	peF2;
	delete	phF2;
}

bool Shop::isSold(ALL_things * all_things)
{
	all_things->drawImage(win2);
	all_things->drawImage(buttonBuy);
	all_things->drawImage(buttonSell);
	all_things->refreshDisplay();

	while (true)
	{
		all_things->waitForEvent();
		all_things->refreshMouseState();

		if (all_things->getMouseButtons() == 1) {
			//naciœniêty LPM, sprawdzanie co zosta³o wciœniête
			if (all_things->getMouseY() > buttonBuy->getY() && all_things->getMouseY() < buttonBuy->getY() + buttonBuy->getH()) {
				if (all_things->getMouseX() > buttonBuy->getX() && all_things->getMouseX() < buttonBuy->getX() + buttonBuy->getW()) {
					return false;
				}
			}
			if (all_things->getMouseY() > buttonSell->getY() && all_things->getMouseY() < buttonSell->getY() + buttonSell->getH()) {
				if (all_things->getMouseX() > buttonSell->getX() && all_things->getMouseX() < buttonSell->getX() + buttonSell->getW()) {
					return true;
				}
			}
		}
	}

	return false;
}

void Shop::showShop(ALL_things * all_things)
{
	all_things->drawImage(win);
	all_things->drawImage(cross);

	all_things->drawImage(dra);
	all_things->drawImage(per);
	all_things->drawImage(pho);

	all_things->drawImage(drS);
	all_things->drawImage(peF);
	all_things->drawImage(phF);

	all_things->drawImage(drS2);
	all_things->drawImage(peF2);
	all_things->drawImage(phF2);

	all_things->refreshDisplay();
}

void Shop::checkForInteraction(ALL_things * all_things, Game* game)
{
	all_things->waitForEvent();
	all_things->refreshMouseState();

	if (all_things->getMouseButtons() == 1) {
		//naciœniêty LPM, sprawdzanie co zosta³o wciœniête
		if (all_things->getMouseY() > cross->getY() && all_things->getMouseY() < cross->getY() + cross->getH()) {
			if (all_things->getMouseX() > cross->getX() && all_things->getMouseX() < cross->getX() + cross->getW()) {
				quit = 1;
				return;
			}
		}

		if (all_things->getMouseY() > dra->getY() && all_things->getMouseY() < dra->getY() + dra->getH()) {
			if (all_things->getMouseX() > dra->getX() && all_things->getMouseX() < dra->getX() + dra->getW()) {
				if (isSold(all_things)) {
					if (game->killDragonIfCan())
						game->setMoney(game->getMoney() + priceDragon / 2);
				}
				else if (game->getMoney() >= priceDragon) {
					game->addDragon(new Dragon());
					game->setMoney(game->getMoney() - priceDragon);
				}
				return;
			}
		}

		if (all_things->getMouseY() > per->getY() && all_things->getMouseY() < per->getY() + per->getH()) {
			if (all_things->getMouseX() > per->getX() && all_things->getMouseX() < per->getX() + per->getW()) {
				if (isSold(all_things)) {
					if (game->killPerytonIfCan())
						game->setMoney(game->getMoney() + pricePeryton / 2);
				}
				else if (game->getMoney() >= pricePeryton) {
					game->addPeryton(new Peryton());
					game->setMoney(game->getMoney() - pricePeryton);
				}
				return;
			}
		}

		if (all_things->getMouseY() > pho->getY() && all_things->getMouseY() < pho->getY() + pho->getH()) {
			if (all_things->getMouseX() > pho->getX() && all_things->getMouseX() < pho->getX() + pho->getW()) {
				if (isSold(all_things)) {
					if (game->killPhoenixIfCan())
						game->setMoney(game->getMoney() + pricePeryton / 2);
				}
				else if (game->getMoney() >= pricePeryton) {
					game->addPhoenix(new Phoenix());
					game->setMoney(game->getMoney() - pricePeryton);
				}
				return;
			}
		}

		if (all_things->getMouseY() > drS->getY() && all_things->getMouseY() < drS->getY() + drS->getH()) {
			if (all_things->getMouseX() > drS->getX() && all_things->getMouseX() < drS->getX() + drS->getW()) {
				if (isSold(all_things)) {
					if (game->getNoDraScales() > 0) {
						game->decreaseDraScales();
						game->setMoney(game->getMoney() + priceDragonScale / 2);
					}
				}
				else if(game->getMoney() >= priceDragonScale) {
					game->setNoDraScales(game->getNoDraScales() + 1);
					game->setMoney(game->getMoney() - priceDragonScale);
				}
				return;
			}
		}

		if (all_things->getMouseY() > peF->getY() && all_things->getMouseY() < peF->getY() + peF->getH()) {
			if (all_things->getMouseX() > peF->getX() && all_things->getMouseX() < peF->getX() + peF->getW()) {
				if (isSold(all_things)) {
					if (game->getNoPerFeathers() > 0) {
						game->decreasePerFeathers();
						game->setMoney(game->getMoney() + pricePerytonFeather / 2);
					}
				}
				else if (game->getMoney() >= pricePerytonFeather) {
					game->setNoPerFeathers(game->getNoPerFeathers() + 1);
					game->setMoney(game->getMoney() - pricePerytonFeather);
				}
				return;
			}
		}

		if (all_things->getMouseY() > phF->getY() && all_things->getMouseY() < phF->getY() + phF->getH()) {
			if (all_things->getMouseX() > phF->getX() && all_things->getMouseX() < phF->getX() + phF->getW()) {
				if (isSold(all_things)) {
					if (game->getNoPhoFeathers() > 0) {
						game->decreasePhoFeathers();
						game->setMoney(game->getMoney() + pricePhoenixFeather / 2);
					}
				}
				else if (game->getMoney() >= pricePhoenixFeather) {
					game->setNoPhoFeathers(game->getNoPhoFeathers() + 1);
					game->setMoney(game->getMoney() - pricePhoenixFeather);
				}
				return;
			}
		}

		if (all_things->getMouseY() > drS2->getY() && all_things->getMouseY() < drS2->getY() + drS2->getH()) {
			if (all_things->getMouseX() > drS2->getX() && all_things->getMouseX() < drS2->getX() + drS2->getW()) {
				if (isSold(all_things)) {
					if (game->getNoDraScales2() > 0) {
						game->setNoDraScales2(game->getNoDraScales2() - 1);
						game->setMoney(game->getMoney() + priceDragonScale);
					}
				}
				else if (game->getMoney() >= priceDragonScale * 2) {
					game->setNoDraScales2(game->getNoDraScales2() + 1);
					game->setMoney(game->getMoney() - priceDragonScale*2);
				}
				return;
			}
		}

		if (all_things->getMouseY() > peF2->getY() && all_things->getMouseY() < peF2->getY() + peF2->getH()) {
			if (all_things->getMouseX() > peF2->getX() && all_things->getMouseX() < peF2->getX() + peF2->getW()) {
				if (isSold(all_things)) {
					if (game->getNoPerFeathers2() > 0) {
						game->setNoPerFeathers2(game->getNoPerFeathers2() - 1);
						game->setMoney(game->getMoney() + pricePerytonFeather);
					}
				}
				else if (game->getMoney() >= pricePerytonFeather*2) {
					game->setNoPerFeathers2(game->getNoPerFeathers2() + 1);
					game->setMoney(game->getMoney() - pricePerytonFeather*2);
				}
				return;
			}
		}

		if (all_things->getMouseY() > phF2->getY() && all_things->getMouseY() < phF2->getY() + phF2->getH()) {
			if (all_things->getMouseX() > phF2->getX() && all_things->getMouseX() < phF2->getX() + phF2->getW()) {
				if (isSold(all_things)) {
					if (game->getNoPhoFeathers2() > 0) {
						game->setNoPhoFeathers2(game->getNoPhoFeathers2() - 1);
						game->setMoney(game->getMoney() + pricePhoenixFeather);
					}
				}
				else if (game->getMoney() >= pricePhoenixFeather*2) {
					game->setNoPhoFeathers2(game->getNoPhoFeathers2() + 1);
					game->setMoney(game->getMoney() - pricePhoenixFeather*2);
				}
				return;
			}
		}

	}
}

void Shop::shopLoop(ALL_things * all_things, Game* game)
{
	quit = 0;

	while (quit == 0){
		showShop(all_things);
		checkForInteraction(all_things, game);
	}
	al_rest(0.3);
}
