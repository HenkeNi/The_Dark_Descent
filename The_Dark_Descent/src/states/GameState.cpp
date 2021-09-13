#include "pch.h"
#include "GameState.h"
#include "../FileHandler.h"

GameState::GameState(StateStack& aStateStack, InputManager& anInputManager)
	: State{ aStateStack, anInputManager }
{
}


void GameState::render()
{
	//std::cout << "Rendering Game\n";

	std::cout << file_handler::getContentFromFile("src/files/SavedGame.txt");

}

void GameState::handleEvent()
{

}

void GameState::update()
{

}

void GameState::initDungeon()
{

}
