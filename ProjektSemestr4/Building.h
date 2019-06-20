#pragma once
#define buildingW 144
#define buildingH 144

class Building
{
private:
	Image* img = nullptr;
	short numberStock = 1;

	int prodTime = 0;
	bool produce = 0;

public:
	Building();
	Building(std::string im, int x, int y);
	~Building();

	short getNumberStock();
	Image* getImg();
	int getProdTime();
	bool getProduce();

	void setNumberStock(short number);
	void setImg(Image* imag);
	void setProdTime(int ss);
	void setProduce(bool yn);

	virtual void createStock(Game* game);
	virtual void action(Game* game);
};