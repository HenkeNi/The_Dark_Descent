#include "pch.h"
#include "Room.h"
#include "Hero.h"
#include "Monster.h"
#include "Utility.h"



Room::Room()
{
	initMonsters();
}


//void Room::openDoor(int aIndex)
//{
//	myDoors[aIndex].openDoor(*this);
//}


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


void Room::printRoomDescription() const
{
	std::cout << myRoomDescription << '\n';
}

void Room::addDoor(Door&& door)
{
	myDoors.push_back(std::move(door));
}

Door& Room::getDoor(int index)
{
	return myDoors.at(index);
}


void Room::setPlayer(Hero* aPlayer)
{
	myPlayer = aPlayer;
}

Hero* Room::getPlayer() const
{
	return myPlayer;
}

Room& Room::setRoomDescription(const std::string& description)
{
	myRoomDescription = description;

	return *this;
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




void Room::showAvailableDoors() const
{
	for (int i{ 0 }; i < myDoors.size(); ++i)
	{
		std::string desc = myDoors[i].getLeadsOut() ? "This door seems to lead out" : "";
		std::cout << (i + 1) << " " << myDoors[i].getDescription() << desc << '\n';
	}
}