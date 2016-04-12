#include "stdafx.h"
#include "PlayerControlledState.h"


PlayerControlledState::PlayerControlledState()
{
	count = 4;
}


PlayerControlledState::~PlayerControlledState()
{
}

void PlayerControlledState::update(Character& character, Grid grid, const Uint8* keyboardState)
{
	character.moveCharacter();

	if (keyboardState == SDL_GetKeyboardState(nullptr))
	{
		character.state = std::make_shared<IdleState>();
	}
}
