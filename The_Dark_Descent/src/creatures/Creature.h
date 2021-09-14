#pragma once
#include "Attributes.h"

class Creature
{
public:
	

	void attack(Creature& someOther) const;
	void takeDamage(int anAmount);

	int getDamageOutput() const; // TODO: expensive to calculate every time?

	void incrementLevel();

	int getCurrentHealth() const;

	int getMaxHealth() const;
	bool isAlive() const;



	void addGold(int anAmount);



private:
	void printAttributes() const;

private:
	Attributes myAttributes; 
	int myHitPoints = 100;
	int myMagicPoints;


	int myLevel;

	int myGold;
	// TODO: carried items...

};

