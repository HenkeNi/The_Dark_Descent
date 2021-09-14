#pragma once

class Dungeon;
class Floor;

class DungeonFactory
{
public:
	Dungeon* create(int aNumberOfFloors);


private:
	Floor getFloor();


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

