#include "pch.h"
#include "DungeonFactory.h"
#include "../dungeon/Dungeon.h"
#include "../dungeon/Floor.h"
#include "../dungeon/Door.h"

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


Floor DungeonFactory::getFloor()
{
	return Floor{};
}


Room DungeonFactory::getRoom()
{
	return Room{};
}