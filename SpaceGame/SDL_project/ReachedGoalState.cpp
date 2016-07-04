#include "stdafx.h"
#include "ReachedGoalState.h"

ReachedGoalState::ReachedGoalState()
{
}

ReachedGoalState::~ReachedGoalState()
{
}

void ReachedGoalState::update(Character& character, PlayerInput::KeyboardDirections direction)
{
	character.hasWon = true;
}