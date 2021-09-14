#include "pch.h"
#include "Door.h"



Door::Door(Room& aFirstRoom, Room& aSecondRoom)
	: myAdjacentRooms{ std::make_pair(aFirstRoom, aSecondRoom) }
{
}


Room& Door::openDoor()
{
	return myAdjacentRooms.second; // ??
}