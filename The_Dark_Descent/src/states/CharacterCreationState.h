#pragma once
#include "State.h"

class CharacterCreationState : public State
{
public:
	CharacterCreationState(StateStack& aStateStack, InputManager& anInputManager);

	virtual void render()		override;
	virtual void handleEvent()  override;
	virtual void update()		override;

private:
	void initMenus();
	void showMenu() const;

	void updatePickedRace();
	void updatePickedClass();

	void storePickedRace(int index);
	void storePickedClass(int index);
	void clearSavedCharacterFile();

private:
	std::stack<std::string> myMenus;
	int						myUserInput;
};

