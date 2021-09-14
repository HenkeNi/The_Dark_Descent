#include "pch.h"
#include "Game.h"


/*
*	Thoughts .. if ui, make player move around. In player. function didMove returns true. In Game check if just moved -> chance of encountering an enemy
* 
* 
*	TODO:
*		- set console window size...
* 
* 
*		- store life left in file
* 
* 
*		- multiple windows
*/




//#include <windows.h>
#include "playground/console_movement/ConsoleMovement.h"

int main()
{
	playground_movement::run();


	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED |
	//	FOREGROUND_GREEN |
	//	FOREGROUND_INTENSITY |
	//	BACKGROUND_BLUE
	//);



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