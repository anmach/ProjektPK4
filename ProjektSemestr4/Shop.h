#pragma once
class Shop
{
private:
	Image* win = nullptr;
	Image* cross = nullptr;
	bool quit = 0;

	Image* win2 = nullptr;
	Image* buttonBuy = nullptr;
	Image* buttonSell = nullptr;

	Image* dra = nullptr;
	Image* per = nullptr;
	Image* pho = nullptr;

	Image* drS = nullptr;
	Image* peF = nullptr;
	Image* phF = nullptr;

	Image* drS2 = nullptr;
	Image* peF2 = nullptr;
	Image* phF2 = nullptr;

public:
	Shop();
	~Shop();

	bool isSold(ALL_things* all_things);
	void showShop(ALL_things* all_things);
	void checkForInteraction(ALL_things* all_things, Game* game);
	void shopLoop(ALL_things* all_things, Game* game);
	
};

