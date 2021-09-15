#include "pch.h"
#include "Hero.h"
#include "Monster.h"
#include "Door.h"
#include "Room.h"

Hero::Hero(Type type)
	: myType{ type }
{
}

void Hero::openDoor(Door& door)
{
	door.openDoor(*myCurrentRoom);
}

void Hero::updateCurrentRoom(Room* room)
{
	myCurrentRoom = room;
}


void Hero::loot(Monster& monster)
{
	
}