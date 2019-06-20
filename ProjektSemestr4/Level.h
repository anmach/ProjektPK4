#pragma once
class Level
{
private:
	int noOfDragons = 0;
	int noOfPhoenixes = 0;
	int noOfPerytons = 0;
	int noOfDragonScales = 0;
	int noOfPhoenixFeathers = 0;
	int noOfPerytonFeathers = 0;
	int noOfDragonScales2 = 0;
	int noOfPhoenixFeathers2 = 0;
	int noOfPerytonFeathers2 = 0;
	int noOfDragonScaleForgess = 0;
	int noOfPhoenixFeatherAlchemists = 0;
	int noOfPerytonFeatherSpecialists = 0;

	int levelNoOfDragons = 1;
	int levelNoOfPhoenixes = 0;
	int levelNoOfPerytons = 1;
	int levelNoOfDragonScales = 0;
	int levelNoOfPhoenixFeathers = 0;
	int levelNoOfPerytonFeathers = 1;
	int levelNoOfDragonScales2 = 0;
	int levelNoOfPhoenixFeathers2 = 0;
	int levelNoOfPerytonFeathers2 = 0;
	int levelNoOfDragonScaleForgess = 0;
	int levelNoOfPhoenixFeatherAlchemists = 0;
	int levelNoOfPerytonFeatherSpecialists = 0;
public:
	Level();
	~Level();

	int getNoOfDragons();
	int getNoOfPhoenixes();
	int getNoOfPerytons();
	int getNoOfDragonScales();
	int getNoOfPhoenixFeathers();
	int getNoOfPerytonFeathers();
	int getNoOfDragonScales2();
	int getNoOfPhoenixFeathers2();
	int getNoOfPerytonFeathers2();
	int getNoOfDragonScaleForges();
	int getNoOfPhoenixFeatherAlchemists();
	int getNoOfPerytonFeatherSpecialists();

	void setNoOfDragons(int x);
	void setNoOfPhoenixes(int x);
	void setNoOfPerytons(int x);
	void setNoOfDragonScales(int x);
	void setNoOfPhoenixFeathers(int x);
	void setNoOfPerytonFeathers(int x);
	void setNoOfDragonScales2(int x);
	void setNoOfPhoenixFeathers2(int x);
	void setNoOfPerytonFeathers2(int x);
	void setNoOfDragonScaleForges(int x);
	void setNoOfPhoenixFeatherAlchemists(int x);
	void setNoOfPerytonFeatherSpecialists(int x);

	bool levelPassed();
};

