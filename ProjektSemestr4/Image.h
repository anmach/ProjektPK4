#pragma once

class Image
{
private:
	ALLEGRO_BITMAP* img = nullptr;
	int x;
	int y;
	int height;
	int width;
public:
	Image();
	Image(std::string imag, int x, int y, int h, int w);
	~Image();

	ALLEGRO_BITMAP* getImg();
	int getX();
	int getY();
	int getH();
	int getW();

	void setX(int newX);
	void setY(int newY);
};

