#include "stdafx.h"
#include "PlayerControlledState.h"


PlayerControlledState::PlayerControlledState()
{
	count = 4;
}


PlayerControlledState::~PlayerControlledState()
{
}

void PlayerControlledState::update(Character& character, Grid grid)
{
	character.moveCharacter();
}
