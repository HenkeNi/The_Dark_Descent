#include "pch.h"
#include "Game.h"


int main()
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	std::rand();
	
	try
	{
		Game game;
		game.run();
	}
	catch (...)
	{
		std::cerr << "Unexpected error. Program terminating...\n";
	}

	return 0;
}