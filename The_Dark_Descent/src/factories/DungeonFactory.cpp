#include "pch.h"
#include "DungeonFactory.h"
#include "../dungeon/Dungeon.h"
#include "../dungeon/Floor.h"


Dungeon* DungeonFactory::create(int aNumberOfFloors)
{
	Dungeon* dungeon = new Dungeon;

	for (int i{ 0 }; i < aNumberOfFloors; ++i)
	{
		Floor floor;
		dungeon->addFloor(getFloor());
	}


	return new Dungeon;

}


Floor DungeonFactory::getFloor()
{
	return Floor{};
}

//void rooms()
//{
//
//}