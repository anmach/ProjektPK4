#include "pch.h"
#include "Bar.h"


Bar::Bar()
{
	int buttonH = 100, buttonW = 144;
	int bottomBarH = 44;

	barImg = new Image("Obrazki/Bar.jpg", 0, 0, buttonH, windowW);
	shopButton = new Image("Obrazki/ShopButton.jpg", 0, 0, buttonH, buttonW);
	feedButton = new Image("Obrazki/Feed.jpg", buttonW, 0, buttonH, buttonW);
	menuButton = new Image("Obrazki/MenuButton.jpg", windowW - buttonW, 0, buttonH, buttonW);
	bottomBarImg = new Image("Obrazki/BottomBar.jpg", 0, windowH - bottomBarH, bottomBarH, windowW);

	draSca = new Image(dragonScaleImageString, windowW - textH2, textY2, stockH, stockW);
	phoFea = new Image(phoenixFeatherImageString, windowW - 2 * textH2, textY2, stockH, stockW);
	perFea = new Image(perytonFeatherImageString, windowW - 3 * textH2, textY2, stockH, stockW);

	draSca2 = new Image(dragonScale2ImageString, windowW - 4 * textH2, textY2, stockH, stockW);
	phoFea2 = new Image(phoenixFeather2ImageString, windowW - 5 * textH2, textY2, stockH, stockW);
	perFea2 = new Image(perytonFeather2ImageString, windowW - 6 * textH2, textY2, stockH, stockW);
}


Bar::~Bar()
{
	delete barImg;
	delete shopButton;
	delete feedButton;
	delete menuButton;
	delete bottomBarImg;

	delete perFea;
	delete phoFea;
	delete draSca;
	delete perFea2;
	delete phoFea2;
	delete draSca2;
}

void Bar::showBar(ALL_things * all_things, Game* game)
{
	all_things->drawImage(barImg);
	all_things->drawImage(feedButton);
	all_things->drawImage(menuButton);
	all_things->drawImage(bottomBarImg);
	all_things->drawImage(shopButton);

	all_things->drawImage(draSca);
	all_things->drawImage(perFea);
	all_things->drawImage(phoFea);

	all_things->drawImage(draSca2);
	all_things->drawImage(perFea2);
	all_things->drawImage(phoFea2);

	showBottomBarText(all_things, game);
}

void Bar::checkForInteraction(ALL_things * all_things, Game * game)
{//Feedujemy
	if (all_things->getMouseY() > feedButton->getY() && all_things->getMouseY() < feedButton->getY() + feedButton->getH()) {
		if (all_things->getMouseX() > feedButton->getX() && all_things->getMouseX() < feedButton->getX() + feedButton->getW()) {
			if (game->getMoney() >= 50) {
				game->setMoney(game->getMoney() - 50);
				game->setFood(game->getFood() + 20);
				game->setGivePredator(1);
			}
			return;
		}
	}

	//Otwieramy sklep
	if (all_things->getMouseY() > shopButton->getY() && all_things->getMouseY() < shopButton->getY() + shopButton->getH())
	{
		if (all_things->getMouseX() > shopButton->getX() && all_things->getMouseX() < shopButton->getX() + shopButton->getW())
		{
			game->setGameState(SHOPPing);
			game->setDeadLock(0);
			return;
		}
	}

	//Otwieramy menu
	if (all_things->getMouseY() > menuButton->getY() && all_things->getMouseY() < menuButton->getY() + menuButton->getH())
	{
		if (all_things->getMouseX() > menuButton->getX() && all_things->getMouseX() < menuButton->getX() + menuButton->getW())
		{
			game->setGameState(MENUing);
			game->setDeadLock(0);
		}
	}
}

void Bar::showBottomBarText(ALL_things * all_things, Game* game)
{
	int l = 15;
	int something = 10;
	int firstTextW = 70;

	al_draw_text(all_things->getFont(), al_map_rgb(0, 0, 0), something, textY, ALLEGRO_ALIGN_LEFT, "Money: ");
	al_draw_textf(all_things->getFont(), al_map_rgb(0, 0, 0), firstTextW, textY, ALLEGRO_ALIGN_LEFT, "%d", game->getMoney());

	al_draw_text(all_things->getFont(), al_map_rgb(0, 0, 0), something + textH1, textY, ALLEGRO_ALIGN_LEFT, "Food: ");
	al_draw_textf(all_things->getFont(), al_map_rgb(0, 0, 0), firstTextW - something + textH1, textY, ALLEGRO_ALIGN_LEFT, "%d", game->getFood());

	//Iloœæ surowców:
	al_draw_textf(all_things->getFont(), al_map_rgb(0, 0, 0), windowW - textH2 + stockW + l, textY, ALLEGRO_ALIGN_LEFT, "%d", game->getNoDraScales());
	al_draw_textf(all_things->getFont(), al_map_rgb(0, 0, 0), windowW - 2 * textH2 + stockW + l, textY, ALLEGRO_ALIGN_LEFT, "%d", game->getNoPhoFeathers());
	al_draw_textf(all_things->getFont(), al_map_rgb(0, 0, 0), windowW - 3 * textH2 + stockW + l, textY, ALLEGRO_ALIGN_LEFT, "%d", game->getNoPerFeathers());

	al_draw_textf(all_things->getFont(), al_map_rgb(0, 0, 0), windowW - 4 * textH2 + stockW + l, textY, ALLEGRO_ALIGN_LEFT, "%d", game->getNoDraScales2());
	al_draw_textf(all_things->getFont(), al_map_rgb(0, 0, 0), windowW - 5 * textH2 + stockW + l, textY, ALLEGRO_ALIGN_LEFT, "%d", game->getNoPhoFeathers2());
	al_draw_textf(all_things->getFont(), al_map_rgb(0, 0, 0), windowW - 6 * textH2 + stockW + l, textY, ALLEGRO_ALIGN_LEFT, "%d", game->getNoPerFeathers2());
}

Image * Bar::getBarImg()
{
	return barImg;
}

Image * Bar::getShopButton()
{
	return shopButton;
}

Image * Bar::getFeedButton()
{
	return feedButton;
}

Image * Bar::getMenuButton()
{
	return menuButton;
}
