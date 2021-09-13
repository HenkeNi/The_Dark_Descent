#include "pch.h"
#include "Utility.h"



namespace Utility
{

	void sleepThread(int someSeconds)
	{
		std::this_thread::sleep_for(std::chrono::seconds(someSeconds));
	}


	int getRandomNumber(int min, int max)
	{
		static constexpr double fraction = 1.0 / (RAND_MAX + 1.0);
		return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
	}

}