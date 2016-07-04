#include "stdafx.h"
#include "WanderingState.h"

WanderingState::WanderingState()
{
}

WanderingState::~WanderingState()
{
}

void WanderingState::update(Character& character, PlayerInput::KeyboardDirections direction)
{
	character.setSpeed(character.wanderSpeed);
	// Moves character in randomly chosen direction
	character.moveCharacter(direction);

	// Character enters dead state when health reaches 0
	if (character.health == 0)
	{
		character.state = std::make_shared<DeadState>();
	}
	// If the oxygen goes beneath acceptableOxygenLevel the character speed reduces
	else if (character.getOxygenLevel(character.getX(), character.getY()) < character.acceptableOxygenLevel)
	{
		character.state = std::make_shared<SuffocatingState>();
		character.isWandering = false;
		character.setSpeed(character.suffocatingSpeed);
	}
	//If the user presses WASD the character will move accordingly
	else if (direction != PlayerInput::KeyboardDirections::None)
	{
		character.state = std::make_shared<PlayerControlledState>();
		character.isWandering = false;
		character.moveCharacter(direction);
	}
	// If the character has reached the goal the game ends
	if (character.reachedGoal(character.getX(), character.getY()))
	{
		character.state = std::make_shared<ReachedGoalState>();
	}
	character.setSpeed(character.walkSpeed);
}
