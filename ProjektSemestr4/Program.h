#pragma once
class Game;
class Menu;

class Program
{
private:
	Image* winScreen;
	Image* button;

	bool playing = 1;

	Game*game = nullptr;
	ALL_things* all_things = nullptr;

public:
	Program();
	~Program();

	void wonGame();
	void loop();
};


