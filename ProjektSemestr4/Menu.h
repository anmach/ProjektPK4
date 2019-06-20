#pragma once

class Game;

class Menu
{
private:
	Image* win = nullptr;
	Image* returnButton = nullptr;
	Image* newGameButton = nullptr;
	Image* quitButton = nullptr;

	int quit = 0; //zmienna, ¿eby wiedzieæ kiedy wyjœæ z menuLoop
public:
	Menu();
	~Menu();

	void showMenu(ALL_things* all_things);
	void checkForInteraction(ALL_things* all_things, Game* game);
	void menuLoop(ALL_things* all_things, Game* game);
};

