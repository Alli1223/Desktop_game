#pragma once
#include "Character.h"
class TraversePath
{
public:
	TraversePath();

	//! Moves the player linearly from one cell to the next
	void TraversePath::LinearMovement(Character& characterOne);

	~TraversePath();
};

