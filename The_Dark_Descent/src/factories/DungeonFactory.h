#pragma once

class Dungeon;
class Floor;
class Room;

// TODO: make namespace...
class DungeonFactory
{
public:
	static DungeonFactory* getInstance();

	Dungeon* create(int aNumberOfFloors);


private:
	DungeonFactory() = default;
	Floor getFloor();
	Room  getRoom();

private:
	static DungeonFactory* myInstance;

	// TODO: read from file...
	std::stack<std::string> myDungeonNames();


};



/*
*		Room can have 1 - 4 doors (1 leads back out the same way)
*		
* 
*		Create a Room (1-4) doors... 
*		Than for each door . create a room
*		needs to be atleast x rooms
*		once x rooms are "done" -> start decreasing the likelyhood of a door appears
* 
* 
*/

