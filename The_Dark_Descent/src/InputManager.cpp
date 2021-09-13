#include "pch.h"
#include "InputManager.h"


void InputManager::ignoreLine() const
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}