#pragma once
#include "Creature.h"

class Hero : public Creature
{
public:
	enum class Type
	{
		Human, Elf, Dwarf
	};

public:
	Hero(Type type);


private:
	Type myType;

};

