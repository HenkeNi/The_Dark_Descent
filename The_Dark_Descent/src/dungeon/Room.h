#pragma once
#include "Monster.h"

class Hero;

class Room
{
public:
	Room(Hero& aPlayer);


	void getInteraction(); // TODO: rename!? 

private:
	void initMonsters();
	
	void encounterEnemy();
	void battle(Hero& aPlayer, Monster& aMonster);

private:
	Hero& myPlayer;
	// FIGHT MANAGER?? - BattleManager (singleton?!)
	
	std::stack<Monster> myMonsters;

};

