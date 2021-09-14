#include "pch.h"
#include "Room.h"

#include "Hero.h"
#include "Monster.h"
#include "Utility.h"


//Room::Room(Hero& aPlayer)
//	: myPlayer{ aPlayer }
//{
//	initMonsters();
//}
Room::Room()
{
	initMonsters();
}



void Room::initMonsters()
{
	// TODO: create monsters -> maybe have factory...
	myMonsters.push({ Monster::Type::Vampire });

}



// Player choses what action to take 
void Room::getInteraction() 
{

	if (Utility::getRandomNumber(1, 6) % 2 == 0)
	{
		encounterEnemy();
	}
}


void Room::encounterEnemy()
{
	Monster& monster = myMonsters.top();
	std::cout << "Something moves in the shadows! A " << monster.getTypeAsString() << " appears\n";

	// TODO: pick an option... (run, fight, etc)


	// If win -> pop() stack...

}


void Room::battle(Hero& aPlayer, Monster& aMonster)
{
	aMonster.attack(aPlayer);
	aMonster.attack(aPlayer);

	while (aPlayer.isAlive() && aMonster.isAlive())
	{
		aPlayer.attack(aMonster); // or chose an option..? - ASK FOR INPUT? (1. attack, 2. run away (escape), 3.

		if (aMonster.isAlive())
		{
			aMonster.attack(aPlayer);
		}
		else
		{
			std::cout << "Player wins!";
			aPlayer.loot(aMonster); // Take gold, check if items to keep?!
			return;
		}
	}

	std::cout << "Enemy wins!\n";


}