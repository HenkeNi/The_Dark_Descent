#include "pch.h"
#include "Game.h"




#include "Monster.h"
#include "Hero.h"


int main()
{

	Monster monster{ Monster::Type::Zombie };
	Hero    hero{ Hero::Type::Human };

	while (monster.isAlive())
		hero.attack(monster);


	std::cout << "MOnster is dead! " << monster.isAlive(); // check health




	/*std::srand(static_cast<unsigned int>(std::time(nullptr)));
	std::rand();
	
	try
	{
		Game game;
		game.run();
	}
	catch (...)
	{
		std::cerr << "Unexpected error. Program terminating...\n";
	}*/

	return 0;
}