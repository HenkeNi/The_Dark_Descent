#pragma once
#include "Creature.h"

class Monster : public Creature
{
public:
	enum class Type
	{
		Zombie, Vampire, Ghost, Goblin, Imp
	};

public:
	Monster(Type type);

private:
	Type myType;
};

