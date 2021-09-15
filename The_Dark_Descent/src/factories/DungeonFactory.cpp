#include "pch.h"
#include "DungeonFactory.h"
#include "../dungeon/Dungeon.h"
#include "../dungeon/Floor.h"
#include "../dungeon/Door.h"
#include "../utility/Utility.h"

DungeonFactory* DungeonFactory::myInstance = nullptr;

Dungeon* DungeonFactory::create(int aNumberOfFloors)
{
	Dungeon* dungeon = new Dungeon;

	for (int i{ 0 }; i < aNumberOfFloors; ++i)
	{
		Floor floor;
		dungeon->addFloor(getFloor());
	}


	return dungeon;

}


DungeonFactory* DungeonFactory::getInstance()
{
	if (!myInstance)
	{
		myInstance = new DungeonFactory();
	}

	return myInstance;
}

Floor DungeonFactory::getFloor()
{
	Floor floor;
	
	//std::stack<Room> rooms;

	//for (int i; i < Utility::getRandomNumber(4, 8); ++i)
	//{
	//	Room room;
	//	

	//	rooms.push(Room{});
	//}

	return Floor{};
}


Room DungeonFactory::getRoom()
{
	return Room{};
}