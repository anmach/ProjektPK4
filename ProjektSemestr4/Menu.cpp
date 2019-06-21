#include "pch.h"
#include "Menu.h"


Menu::Menu()
{
	int winH = 400, winW = 300;
	int buttonH = 100, buttonW = 200;
	win = new Image("Obrazki/MenuB.jpg", windowW / 2 - winW / 2, windowH / 2 - winH / 2, winH, winW);
	returnButton = new Image("Obrazki/ReturnButton.jpg", windowW / 2 - buttonW / 2, windowH / 2 - winH / 2 + winH / 3 - buttonH / 2, buttonH, buttonW);
	newGameButton = new Image("Obrazki/NewGameButton.jpg", windowW / 2 - buttonW / 2, windowH / 2 - winH / 2 + 2 * winH / 3 - buttonH / 2, buttonH, buttonW);
	quitButton = new Image("Obrazki/QuitButton.jpg", windowW / 2 - buttonW / 2, windowH / 2 - winH / 2 + 3 * winH / 3 - buttonH / 2, buttonH, buttonW);
}


Menu::~Menu()
{
	delete win;
	delete returnButton;
	delete quitButton;
	delete newGameButton;
}

void Menu::showMenu(ALL_things * all_things)
{
	all_things->drawImage(win);
	all_things->drawImage(returnButton);
	all_things->drawImage(quitButton);
	all_things->drawImage(newGameButton);

	all_things->refreshDisplay();
}

void Menu::checkForInteraction(ALL_things * all_things, Game * game)
{
	all_things->waitForEvent();
	all_things->refreshMouseState();

	if (all_things->getMouseButtons() == 1) {
		if (all_things->getMouseY() > returnButton->getY() && all_things->getMouseY() < returnButton->getY() + returnButton->getH()) {
			if (all_things->getMouseX() > returnButton->getX() && all_things->getMouseX() < returnButton->getX() + returnButton->getW()) {
				quit = 1;
				game->setGameState(PLAYing);
				game->setDeadLock(1);
				return;
			}
		}

		if (all_things->getMouseY() > newGameButton->getY() && all_things->getMouseY() < newGameButton->getY() + newGameButton->getH()) {
			if (all_things->getMouseX() > newGameButton->getX() && all_things->getMouseX() < newGameButton->getX() + newGameButton->getW()) {
				game->doRefreshGame();
				game->setGameState(ENDing);
				game->setDeadLock(0);
				quit = 1;
				return;
			}
		}

		if (all_things->getMouseY() > quitButton->getY() && all_things->getMouseY() < quitButton->getY() + quitButton->getH()) {
			if (all_things->getMouseX() > quitButton->getX() && all_things->getMouseX() < quitButton->getX() + quitButton->getW()) {
				game->setGameState(ENDing);
				game->setDeadLock(0);
				quit = 1;
				return;
			}
		}
	}
}

void Menu::menuLoop(ALL_things * all_things, Game * game)
{
	showMenu(all_things);
	quit = 0;

	while (quit == 0)
	{
		checkForInteraction(all_things, game);
	}
}

