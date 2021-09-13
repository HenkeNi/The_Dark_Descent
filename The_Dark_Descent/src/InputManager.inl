
template <typename T>
T InputManager::getUserInput()
{
	T userInput;

	while (true)
	{
		std::cout << "Input here: ";
		std::cin >> userInput;

		// Check for failed extraction
		if (std::cin.fail())
		{
			std::cin.clear();
			ignoreLine();
			std::cout << "Invalid Input!\n";
		}
		else
		{
			ignoreLine();
			return userInput;
		}
	}
}