#pragma once
class MoveDirection
{
public:
	MoveDirection();
	~MoveDirection();

	void chooseDirection(const Uint8* keyboardState);
};

