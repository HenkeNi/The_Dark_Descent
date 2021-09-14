#pragma once
#include "State.h"
#include "Hero.h"

class GameState : public State
{
public:
	GameState(StateStack& aStateStack, InputManager& anInputManager);
	~GameState();

	virtual void render()		override;
	virtual void handleEvent()  override;
	virtual void update()		override;

private:
	void initDungeon();
	void initPlayer();

	void showGameOver();

private:
	//Dungeon myDungeon;
	Hero*    myPlayer; // - in constructor readfrom file which race (make function)
};

