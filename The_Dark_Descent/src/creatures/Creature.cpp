#include "pch.h"
#include "Creature.h"


void Creature::attack(Creature& someOther) const
{
	int damageDealt = getDamageOutput();
	someOther.takeDamage(damageDealt);
}

void Creature::takeDamage(int anAmount)
{
	myHitPoints -= anAmount;

	if (myHitPoints < 0) { myHitPoints = 0; } 
}

int Creature::getDamageOutput() const
{
	return 25;
}




void Creature::incrementLevel()
{
	++myLevel;
	// increment stats?
}


int Creature::getCurrentHealth() const
{
	return myHitPoints;
}


int Creature::getMaxHealth() const
{
	return myAttributes.myVitality * 100; // FIX magic number...
}


bool Creature::isAlive() const
{
	return myHitPoints > 0;
}


void Creature::addGold(int anAmount)
{
	assert(anAmount >= 0);
	myGold += anAmount;
}


void Creature::printAttributes() const
{

}