#include "pch.h"
#include "State.h"
#include "../StateStack.h"
#include "../InputManager.h"

State::State(StateStack& aStateStack, InputManager& anInputManager)
	: myStateStackRef{ aStateStack }, myInputManagerRef{ anInputManager }
{
}

void State::requestStackPop()
{
	myStateStackRef.popState();
}

void State::requestStackPush(std::unique_ptr<State> aStatePtr)
{
	myStateStackRef.pushState(std::move(aStatePtr));
}

void State::requestStackClear()
{
	myStateStackRef.clearStates();
}