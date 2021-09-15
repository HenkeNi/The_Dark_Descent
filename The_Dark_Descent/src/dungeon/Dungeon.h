#pragma once
#include "Floor.h"

class Dungeon
{
public:

	//void addFloor(std::unique_ptr<Floor> floor);
	void addFloor(Floor floor);

	void enterRoom();

	void render();
	void handleEvent();
	void update();

private:
	//std::vector<std::unique_ptr<Floor>> myFloores;
	std::string myDungeonName;
	std::vector<Floor> myFloores;
};


