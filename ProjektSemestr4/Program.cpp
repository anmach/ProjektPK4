#include "pch.h"
#include "Program.h"

Program::Program()
{
	int buttonH = 100, buttonW = 200;
	all_things = new ALL_things();
	game = new Game(all_things);
	winScreen = new Image("Obrazki/MenuBackground.png", 0, 0, windowH, windowW);
	button = new Image("Obrazki/QuitButton.jpg", windowW / 2 - buttonW / 2, windowH / 2 - buttonH / 2, buttonH, buttonW);
}

Program::~Program()
{
	delete game;
	delete all_things;
	delete winScreen;
	delete button;
}

void Program::wonGame()
{
	all_things->drawImage(winScreen);
	all_things->drawImage(button);
	all_things->refreshDisplay();

	while (true)
	{
		all_things->waitForEvent();
		all_things->refreshMouseState();

		if (all_things->getMouseButtons() == 1) {
			//naciœniêty LPM, sprawdzanie co zosta³o wciœniête
			if (all_things->getMouseY() > button->getY() && all_things->getMouseY() < button->getY() + button->getH()) {
				if (all_things->getMouseX() > button->getX() && all_things->getMouseX() < button->getX() + button->getW()) {
					break;
				}
			}
		}
	}
}

void Program::loop()
{
	while (playing){
		game->gameLoop();
		if (game->getRefreshGame()){
			delete game;
			game = new Game(all_things);
		}
		else
			playing = 0;
	
	}
	if (game->getWonGame()) {
		wonGame();
	}
}
