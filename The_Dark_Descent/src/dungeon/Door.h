#pragma once

class Room;

class Door
{
public:
	Door(Room* aFirstRoom, Room* aSecondRoom);

	void openDoor(Room& currentRoom);
	//void walkThroughDoor(Room& from, Room& to);

	bool			   getLeadsOut()    const;
	const std::string& getDescription() const;

private:
	std::pair<Room*, Room*> myAdjacentRooms;
	std::string myDescription;
	bool myLeadsOut;
};

