#pragma once
#include "Creature.h"

class Monster;

class Hero : public Creature
{
public:
	enum class Type
	{
		Human, Elf, Dwarf
	};

public:
	Hero(Type type);


	void loot(Monster& monster);

private:
	Type myType;

};

