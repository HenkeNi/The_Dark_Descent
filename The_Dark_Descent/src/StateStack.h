#pragma once
#include "State.h"


// TODO: Rename StateManager??
class StateStack
{
public:
	void render();
	void handleEvent(); // or handleInput??
	void update();

	void pushState(std::unique_ptr<State> aStatePtr);
	void popState();
	void clearStates();

	inline bool isEmpty() { return myStates.empty(); }

private:
	std::stack<std::unique_ptr<State>> myStates;
};

