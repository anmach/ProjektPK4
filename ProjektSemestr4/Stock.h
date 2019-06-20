#pragma once
#define stockH 20
#define stockW 20
class Image;

class Stock
{
private:
	short timeProduction;
	Image* img;
public:
	Stock();
	Stock(short time, std::string imag, int x, int y);
	~Stock();

	short getTimeProduction();
	Image* getImg();

	void setTimeProduction(short time);
	void setImg(Image* imag);
};