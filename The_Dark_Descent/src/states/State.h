#pragma once

class InputManager;
class StateStack;

class State
{
public:
	State(StateStack& aStateStack, InputManager& anInputManager);
	virtual ~State() = default;

	virtual void render()      = 0;
	virtual void handleEvent() = 0;
	virtual void update()      = 0;

protected:
	void requestStackPop();
	void requestStackPush(std::unique_ptr<State> aStatePtr);
	void requestStackClear();

protected:
	InputManager& myInputManagerRef; // use function and keep private?! - requestuserinput (template)

private:
	StateStack& myStateStackRef;

};

