#pragma once
#define animalH 20
#define animalW 50

class Game;

class Animal
{
private:
	short dx, dy;
	short hunger = 0;
	short priceSell;
	Image* img;
	short defaultProductionTime = 0;
	short productionTime;
	short maxHunger;

public:
	Animal();
	Animal(short pSell, std::string im, int x, int y, short proTime, short maxHun);
	~Animal();

	short getHunger();
	short getMaxHunger();
	short getPriceSell();
	Image* getImg();
	short getProductionTime();
	short getDefaultProductionTime();
	short getDx();
	short getDy();

	void setHunger(short hunger);
	void setPriceSell(short price);
	void setImg(Image* imag);
	void setProductionTime(short x);
	void setDx(short x);
	void setDy(short x);

	virtual void makeStock(Game* game);
	void walk();
	void eat();
	void getMoreHunger();
	void shortenProductionTime(short x);

	virtual void action(Game* game);
};