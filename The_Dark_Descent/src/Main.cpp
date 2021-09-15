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
//#include "playground/console_movement/ConsoleMovement.h"


#include "Room.h"
#include "Door.h"
#include "Hero.h"



/*
*	Player keeps track of which rooms his in??
*		also have logic for open Doors?? - gets it from the Room* in Hero... 
*		
*	Hero:
*		OpenDoor()
*		
* 
* 
*/





int main()
{

	Hero hero{ Hero::Type::Human };

	Room room1;
	Room room2;
	room1.setPlayer(&hero);
	room1.addDoor({ &room1, &room2 });
	room2.setPlayer(nullptr);

	std::cout << "Player is in Room 1 ?" << (room1.getPlayer() != nullptr ? true : false) << '\n';
	std::cout << "Player is in Room 2 ?" << (room2.getPlayer() != nullptr ? true : false) << '\n';

	hero.updateCurrentRoom(&room1);
	hero.openDoor(room1.getDoor(0));

	std::cout << "Player is in Room 1 ?" << (room1.getPlayer() != nullptr ? true : false) << '\n';
	std::cout << "Player is in Room 2 ?" << (room2.getPlayer() != nullptr ? true : false) << '\n';




	system("pause");
	




	//playground_movement::run();


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