#pragma once
#include "InputManager.h"
#include "StateStack.h"

// TODO: load all enemy types from files? store in resource mangaer?

class Game
{
public:
	Game();
	~Game();

	void run();

private:
	void render();
	void processEvents();
	void update();

	void initStates();
	void displayIntro();
	void clearScreen(); // TODO: make a renderer or something (console class?)

private:
	StateStack	 myStateStack;
	InputManager myInputManager;
};

