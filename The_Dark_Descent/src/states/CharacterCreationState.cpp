#include "pch.h"
#include "CharacterCreationState.h"
#include "../FileHandler.h"
#include "../InputManager.h"
#include "Utility.h"

CharacterCreationState::CharacterCreationState(StateStack& aStateStack, InputManager& anInputManager)
	: State{ aStateStack, anInputManager }
{
	initMenus();
	clearSavedCharacterFile();
}

void CharacterCreationState::render()
{
	showMenu();
}

void CharacterCreationState::handleEvent()
{
	myUserInput = myInputManagerRef.getUserInput<int>();
}

void CharacterCreationState::update()
{
	myMenus.size() > 1 ? updatePickedRace() : updatePickedClass();
}

void CharacterCreationState::initMenus()
{
	// Clear stack of old menus
	while (!myMenus.empty())
	{
		myMenus.pop();
	}

	myMenus.emplace(file_handler::getContentFromFile("src/files/menus/ClassSelection.txt"));
	myMenus.emplace(file_handler::getContentFromFile("src/files/menus/RaceSelection.txt"));
}

void CharacterCreationState::showMenu() const
{
	std::cout << myMenus.top() << '\n';
}

void CharacterCreationState::updatePickedRace()
{
	switch (myUserInput)
	{
	case 1:
	case 2:
	case 3:
		storePickedRace(myUserInput);
		myMenus.pop();
		break;
	default:
		std::cout << "Please pick a valid alternative!\n";
		Utility::sleepThread();
		break;
	}

}

void CharacterCreationState::updatePickedClass()
{
	switch (myUserInput)
	{
	case 1:
	case 2:
	case 3:
		storePickedClass(myUserInput);
		requestStackPop();
		break;
	case 4:
		initMenus();
		clearSavedCharacterFile();
		break;
	default:
		std::cout << "Please pick a valid alternative!\n";
		Utility::sleepThread();
		break;
	}
}

void CharacterCreationState::storePickedRace(int index)
{
	std::string pickedRace = index == 1 ? "Human\n" : index == 2 ? "Elf\n" : "Dwarf\n";
	file_handler::writeToFile("src/files/SavedGame.txt", pickedRace);
}

void CharacterCreationState::storePickedClass(int index)
{
	std::string pickedClass = index == 1 ? "Warrior\n" : index == 2 ? "Rogue\n" : "Sorcerer\n";
	file_handler::writeToFile("src/files/SavedGame.txt", pickedClass);
}

void CharacterCreationState::clearSavedCharacterFile()
{
	file_handler::eraseContentOfFile("src/files/SavedGame.txt");
}