#include "pch.h"
#include "StateStack.h"

void StateStack::render()
{
	if (!myStates.empty())
	{
		myStates.top()->render();
	}
}

void StateStack::handleEvent()
{
	if (!myStates.empty())
	{
		myStates.top()->handleEvent();
	}
}

void StateStack::update()
{
	if (!myStates.empty())
	{
		myStates.top()->update();
	}
}

void StateStack::pushState(std::unique_ptr<State> aStatePtr)
{
	myStates.push(std::move(aStatePtr));
}

void StateStack::popState()
{
	if (!myStates.empty())
	{
		myStates.pop();
	}
}

void StateStack::clearStates()
{
	while (!myStates.empty())
	{
		myStates.pop();
	}
}