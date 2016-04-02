#pragma once
#include"CharacterState.h"

class PlayerControlledState: public CharacterState
{
public:
	PlayerControlledState();
	~PlayerControlledState();

	void update(Character& character, std::string direction)
	{
		character.playerControlled();
	}
};

