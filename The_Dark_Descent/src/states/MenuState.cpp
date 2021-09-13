#include "pch.h"
#include "MenuState.h"
#include "../InputManager.h"
#include "../FileHandler.h"
#include "../StateStack.h"
#include "Utility.h"

MenuState::MenuState(StateStack& aStateStack, InputManager& anInputManager)
	: State{ aStateStack, anInputManager }
{
	initMenu();
}

void MenuState::render()
{
	showMenu();
}

void MenuState::handleEvent()
{
	myUserInput = myInputManagerRef.getUserInput<int>();
}

void MenuState::update()
{
	switch (myUserInput)
	{
	case 1:
		requestStackPop();
		break;
	case 2:
		std::cout << "Not implemented\n";
		break;
	case 3:
		requestStackClear();
		break;
	default:
		std::cout << "Please pick a valid alternative!\n";
		Utility::sleepThread();
		break;
	}
}

void MenuState::initMenu()
{
	myMenu = file_handler::getContentFromFile("src/files/menus/MainMenu.txt");
}

void MenuState::showMenu() const
{
	std::cout << myMenu << '\n';
}