#pragma once
#include "Floor.h"

class Dungeon
{
public:

	//void addFloor(std::unique_ptr<Floor> floor);
	void addFloor(Floor floor);

private:
	//std::vector<std::unique_ptr<Floor>> myFloores;
	std::vector<Floor> myFloores;
};

