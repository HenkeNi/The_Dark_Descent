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




std::vector<std::vector<char>> map
{
	{'o', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
	{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
	{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
	{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
	{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
	{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
	{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
	{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
	{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
	{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

std::pair<int, int> playerPosition;

void handleInput()
{

	// write: direction to walk:    - ([Enter] to confirm)


	char c;
	//std::cin >> c;
	scanf_s("%c", &c);

	switch (c)
	{
	case 'w':
		if (playerPosition.first > 0)
		{
			--playerPosition.first;
		}
		break;
	case 's':
		if (playerPosition.first < 10)
		{
			++playerPosition.first;
		}
		break;
	case 'a':
		if (playerPosition.second > 0)
		{
			--playerPosition.second;
		}
		break;
	case 'd':
		if (playerPosition.second < 10)
		{
			++playerPosition.second;
		}
		break;
	}
}

void drawMap()
{
	system("CLS");
	for (int i{ 0 }; i < 10; ++i)
	{
		for (int j{ 0 }; j < 10; ++j)
		{
			std::cout << map.at(i).at(j);
		}
		std::cout << "\n";
	}

	std::cout << "\n\n"
		"Player: o\n"
		"Chest: x\n";

	std::this_thread::sleep_for(std::chrono::seconds(1));
}


void render()
{
	while (true)
	{
		drawMap();
	}
}

void processInput()
{
	while (true)
	{
		handleInput();

	}
}

void update()
{
	while (true)
	{

		/*for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				map.at(i).at(j) = '#';
			}
		}*/
		map.at(playerPosition.first).at(playerPosition.second) = 'o';

	}
}










int main()
{


	playerPosition = std::make_pair<int, int>(0, 0);

	std::thread renderThread(render);
	std::thread inputThread(processInput);
	std::thread updateThread(update);

	renderThread.join();
	inputThread.join();
	updateThread.join();

	std::cout << "Finished!\n";

	/*char characterMap[10][10]
	{
		{'o', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
		{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
		{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
		{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
		{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
		{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
		{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
		{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
		{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
		{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
	};*/


	//while (true)
	//{
	//	for (int i{ 0 }; i < 10; ++i)
	//	{
	//		for (int j{ 0 }; j < 10; ++j)
	//		{
	//			std::cout << characterMap[i][j];
	//			
	//		}
	//		std::cout << '\n';
	//	}

	//	// TODO: multitreading...

	//	char c;
	//	std::cin >> c;
	//	if (c == 's')
	//	{
	//		characterMap[0][0] = '#';
	//		characterMap[1][0] = 'o';
	//	}

	//	system("CLS");
	//}














	//HANDLE consoleColor;
	//consoleColor = GetStdHandle(STD_OUTPUT_HANDLE);

	//SetConsoleTextAttribute(consoleColor, 1);

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