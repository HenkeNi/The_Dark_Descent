#pragma once

class InputManager
{
public:
	template <typename T>
	T getUserInput();

private:
	void ignoreLine() const;
};

#include "InputManager.inl"