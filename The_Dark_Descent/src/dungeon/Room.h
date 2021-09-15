#pragma once
#include "Monster.h"
#include "Door.h"

class Hero;

class Room
{
public:
	enum class Type 
	{
		Entrance, TreaureChamber
	};

public:
	Room();

	//void openDoor(int aIndex, Room& aCurrentRoom);
	//void openDoor(int aIndex);

	void getInteraction(); // TODO: rename!? 
	void printRoomDescription() const;
	
	void addDoor(Door&& door);

	Door& getDoor(int index);

	void setPlayer(Hero* aPlayer);
	Hero* getPlayer() const;

	Room& setRoomDescription(const std::string& description);

	void showAvailableDoors() const;

private:
	void initMonsters();
	
	void encounterEnemy();
	void battle(Hero& aPlayer, Monster& aMonster);

private:
	Hero* myPlayer;
	std::string myRoomDescription;
	std::vector<Door> myDoors;

	std::stack<Monster> myMonsters;
	

	// ROOM also keeps track of which dungeon it belongs to? and floor?

	// FIGHT MANAGER?? - BattleManager (singleton?!)
};

