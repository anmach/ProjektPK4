#pragma once
class Animal;

class Predator
{
private:
	Image* img;
	bool hunting = 0;
	Animal* prey = nullptr;
	std::string typeOfprey = "";
public:
	Predator();
	~Predator();

	Image* getImg();
	void hunt(Game* game);
};

