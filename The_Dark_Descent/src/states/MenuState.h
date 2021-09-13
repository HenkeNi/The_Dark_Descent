#pragma once
#include "State.h"

class MenuState : public State
{
public:
	MenuState(StateStack& aStateStack, InputManager& anInputManager);

	virtual void render()		override;
	virtual void handleEvent()  override;
	virtual void update()		override;

private:
	void initMenu();
	void showMenu() const;

private:
	std::string myMenu;
	int myUserInput = 0;

};

