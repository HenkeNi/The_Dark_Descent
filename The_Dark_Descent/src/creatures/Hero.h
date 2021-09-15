#pragma once
#include "Creature.h"

class Door;
class Room;
class Monster;

class Hero : public Creature
{
public:
	enum class Type
	{
		Human, Elf, Dwarf
	};

public:
	Hero(Type type);


	void openDoor(Door& door);
	void loot(Monster& monster);

	void updateCurrentRoom(Room* room);

private:
	Type myType;
	Room* myCurrentRoom; // Change to Location* (interface or abstract class)    

};

