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

	if (!(keyboardState[SDL_SCANCODE_W] || keyboardState[SDL_SCANCODE_A] || keyboardState[SDL_SCANCODE_S] || keyboardState[SDL_SCANCODE_D]))
	{
		character.state = std::make_shared<IdleState>();
	}
}
