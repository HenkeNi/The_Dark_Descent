#include "pch.h"
#include "Door.h"
#include "Room.h"


Door::Door(Room* aFirstRoom, Room* aSecondRoom)
	: myAdjacentRooms{ std::make_pair(aFirstRoom, aSecondRoom) }
{
}


void Door::openDoor(Room& currentRoom)
{
	if (myAdjacentRooms.first == &currentRoom)
	{
		myAdjacentRooms.second->setPlayer(currentRoom.getPlayer());
		currentRoom.setPlayer(nullptr);
	}


	//return myAdjacentRooms.second; // ??
}


bool Door::getLeadsOut() const
{
	return myLeadsOut;
}

const std::string& Door::getDescription() const
{
	return myDescription;
}