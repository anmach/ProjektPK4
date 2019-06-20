#pragma once

class ShopB
{
	Image * win = nullptr;
	Image * cross = nullptr;

	Image *dSF = nullptr;
	Image *pFA = nullptr;
	Image *pFS = nullptr;

	bool quit = 0;

public: 
	ShopB();
	~ShopB();

	void checkForInteraction(ALL_things* all_things, Game* game, Image* img);
	void showShop(ALL_things* all_things);
	void shopLoop(ALL_things* all_things, Game* game, Image* imag);
};