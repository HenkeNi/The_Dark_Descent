#pragma once
#include "State.h"
#include "Hero.h"

class GameState : public State
{
public:
	GameState(StateStack& aStateStack, InputManager& anInputManager);

	virtual void render()		override;
	virtual void handleEvent()  override;
	virtual void update()		override;

private:
	void initDungeon();

private:
	//Dungeon myDungeon;
	//Hero    myHero; - in constructor readfrom file which race (make function)
};

