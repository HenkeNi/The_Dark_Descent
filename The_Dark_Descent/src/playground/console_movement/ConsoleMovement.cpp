#include "pch.h"
#include "ConsoleMovement.h"






namespace playground_movement
{




	std::vector<std::vector<char>> map
	{
		{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
		{'#', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
		{'#', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
		{'#', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
		{'#', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
		{'#', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
		{'#', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
		{'#', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
		{'#', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
		{'#', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
		{'#', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
		{'#', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
		{'#', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
		{'#', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
		{'#', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
		{'#', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
		{'#', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
		{'#', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
		{'#', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
		{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
	};

	bool shouldUpdate = true;
	std::pair<int, int> playerPosition;




	void handleInput()
	{

		// write: direction to walk:    - ([Enter] to confirm)
		shouldUpdate = false;

		int input;
		input = _getch();

		switch (input)
		{
		case KEY_W:
			if (playerPosition.first > 0)
			{
				--playerPosition.first;
				shouldUpdate = true;
			}
			break;
		case KEY_S:
			if (playerPosition.first < 10)
			{
				++playerPosition.first;
				shouldUpdate = true;
			}
			break;
		case KEY_A:
			if (playerPosition.second > 0)
			{
				--playerPosition.second;
				shouldUpdate = true;
			}
			break;
		case KEY_D:
			if (playerPosition.second < 10)
			{
				++playerPosition.second;
				shouldUpdate = true;
			}
			break;
		}
	}



	void drawMap()
	{
		if (!shouldUpdate)
			return;

		system("CLS");
		for (int i{ 0 }; i < map.size(); ++i)
		{
			for (int j{ 0 }; j < map.at(i).size(); ++j)
			{
				std::cout << map[i][j];
			}
			std::cout << "\n";
		}

		std::cout << "\n\n"
			"Player: o\n"
			"Chest: x\n";

		//std::this_thread::sleep_for(std::chrono::seconds(1));
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
					if (i == playerPosition.first && j == playerPosition.second)
						map[i][j] == 'o';
					else
						map[i][j] == '#';
				}
			}*/
			map.at(playerPosition.first).at(playerPosition.second) = 'o';
		}
	}



	void run()
	{

		playerPosition = std::make_pair<int, int>(0, 0);

		std::thread renderThread(render);
		std::thread inputThread(processInput);
		std::thread updateThread(update);

		renderThread.join();
		inputThread.join();
		updateThread.join();

		std::cout << "Finished!\n";

	}



}

