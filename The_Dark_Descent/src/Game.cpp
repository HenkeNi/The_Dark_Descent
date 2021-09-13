#include "pch.h"
#include "Game.h"
#include "FileHandler.h"

#include "CharacterCreationState.h"
#include "GameState.h"
#include "MenuState.h"

#include "Utility.h"


Game::Game()
{
	initStates();
}

Game::~Game()
{
	std::cout << "Thank you for playing!\n";
}


void Game::run()
{
	displayIntro();

	while (!myStateStack.isEmpty())
	{
		clearScreen();

		render();
		processEvents();
		update();
	}
}

void Game::render()
{
	myStateStack.render();
}

void Game::processEvents()
{
	myStateStack.handleEvent();
}

void Game::update()
{
	myStateStack.update();
}

void Game::initStates()
{
	myStateStack.pushState(std::make_unique<GameState>(myStateStack, myInputManager));
	myStateStack.pushState(std::make_unique<CharacterCreationState>(myStateStack, myInputManager));
	myStateStack.pushState(std::make_unique<MenuState>(myStateStack, myInputManager));
}

void Game::displayIntro()
{
	std::cout << file_handler::getContentFromFile("src/files/titles/GameTitle.txt");
	Utility::sleepThread();
}

void Game::clearScreen()
{
	system("CLS");
}