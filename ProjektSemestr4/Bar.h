#pragma once
class Bar
{
private:
	//Obrazki pask�w i przycisk�w:
	Image* barImg = nullptr;
	Image* shopButton = nullptr;
	Image* feedButton = nullptr;
	Image* menuButton = nullptr;
	Image* bottomBarImg = nullptr;

	//Obrazki surowc�w:
	Image* perFea = nullptr;
	Image* phoFea = nullptr;
	Image* draSca = nullptr;
	Image* perFea2 = nullptr;
	Image* phoFea2 = nullptr;
	Image* draSca2 = nullptr;

	//Wysoko�ci, y po�o�enia tekstu
	int textH1 = 120;
	int textH2 = 100;
	int textY = 690;
	int textY2 = 685;

public:
	Bar();
	~Bar();

	Image* getBarImg();
	Image* getShopButton();
	Image* getFeedButton();
	Image* getMenuButton();

	void showBar(ALL_things* all_things, Game*game);
	void checkForInteraction(ALL_things* all_things, Game* game);
	void showBottomBarText(ALL_things* all_things, Game* game);
};

