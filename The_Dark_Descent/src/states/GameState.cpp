#include "pch.h"
#include "GameState.h"
#include "../InputManager.h"
#include "../FileHandler.h"
#include "../utility/Utility.h"

GameState::GameState(StateStack& aStateStack, InputManager& anInputManager)
	: State{ aStateStack, anInputManager }
{
	initDungeon();
	initPlayer();
}

GameState::~GameState()
{
	delete myPlayer;
}


void GameState::render()
{
	//std::cout << "Rendering Game\n";

	std::cout << file_handler::getContentFromFile("src/files/SavedGame.txt");

}

#include "Monster.h"
void GameState::handleEvent()
{
	
	//if (myInputManagerRef.getUserInput<int>() == 1)
	//{
	//	Monster monster{ Monster::Type::Zombie };
	//	monster.attack(*myPlayer);
	//}
}

void GameState::update()
{





	// Player is dead
	if (!myPlayer->isAlive())
	{
		showGameOver();
		requestStackPop();
	}

}

void GameState::initDungeon()
{

}

void GameState::initPlayer()
{
	myPlayer = new Hero{ Hero::Type::Human };
}



void GameState::showGameOver()
{
	std::cout <<file_handler::getContentFromFile("src/files/titles/GameOverTitle.txt") << '\n';
	Utility::sleepThread();
}
