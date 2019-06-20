#include "pch.h"
#include "Predator.h"


Predator::Predator()
{
	img = new Image(predatorImageString, farmX, farmY, animalH, animalW);
}


Predator::~Predator()
{
	delete img;
	if(prey!= nullptr)
		delete prey;
}

Image * Predator::getImg()
{
	return img;
}

void Predator::hunt(Game* game)
{
	if (!hunting) {
		hunting = 1;
		prey = game->findNearestAnimal(img->getX(), img->getY(), typeOfprey);
		if (prey == nullptr)
			game->killPredator();
	}
	else {
		if (prey->getImg()->getX() == img->getX()) {
			if (prey->getImg()->getY() == img->getY()) {
				if (typeOfprey == "dragon")
					game->killDragon((Dragon*)prey);
				if (typeOfprey == "phoenix")
					game->killPhoenix((Phoenix*)prey);
				if (typeOfprey == "peryton")
					game->killPeryton((Peryton*)prey);
				prey = nullptr;
				hunting = 0;
			}
			else if (prey->getImg()->getY() > img->getY())
				img->setY(img->getY() + 4);
			else if (prey->getImg()->getY() < img->getY())
				img->setY(img->getY() - 4);
		}
		else if (prey->getImg()->getX() > img->getX()) {
			if (prey->getImg()->getY() == img->getY())
				img->setX(img->getX() + 3);
			else if (prey->getImg()->getY() > img->getY()) {
				img->setX(img->getX() + 2);
				img->setY(img->getY() + 2);
			}
			else if (prey->getImg()->getY() < img->getY()) {
				img->setX(img->getX() + 1);
				img->setY(img->getY() - 1);
			}
		}
		else if (prey->getImg()->getX() < img->getX()) {
			if (prey->getImg()->getY() == img->getY())
				img->setX(img->getX() - 3);
			else if (prey->getImg()->getY() > img->getY()) {
				img->setX(img->getX() - 2);
				img->setY(img->getY() + 2);
			}
			else if (prey->getImg()->getY() < img->getY()) {
				img->setX(img->getX() - 1);
				img->setY(img->getY() - 1);
			}
		}
	}
}
