#include "pch.h"
#include "Monster.h"


Monster::Monster(Type type)
	: myType{ type }
{
}




std::string Monster::getTypeAsString()
{
	switch (myType)
	{
	case Monster::Type::Zombie:
		return "Zombie";
	case Monster::Type::Vampire:
		return "Vampire";
	case Monster::Type::Ghost:
		return "Ghost";
	case Monster::Type::Goblin:
		return "Goblin";
	case Monster::Type::Imp:
		return "Imp";
	default:
		return "Unknown";
	}
}