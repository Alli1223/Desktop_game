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
	character.moveCharacter(keyboardState);

	if (character.health == 0)
	{
		character.state = std::make_shared<DeadState>();
		character.isAlive = false;
		count = 2;
	}
	else if (!(keyboardState[SDL_SCANCODE_W] || keyboardState[SDL_SCANCODE_A] || keyboardState[SDL_SCANCODE_S] || keyboardState[SDL_SCANCODE_D]))
	{
		character.state = std::make_shared<IdleState>();
		character.state->timer = 1;
	}
	else if (character.oxygenLevel < 50)
	{
		character.state = std::make_shared<LowOxygenState>();
		character.setSpeed(1);
		count = 3;
	}
}
