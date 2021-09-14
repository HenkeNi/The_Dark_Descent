#pragma once

//class Room;
#include "Room.h"

class Door
{
public:
	Door(Room& aFirstRoom, Room& aSecondRoom);

	Room& openDoor();
	//void walkThroughDoor(Room& from, Room& to);


private:
	std::pair<Room, Room> myAdjacentRooms;

};

