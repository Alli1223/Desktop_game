#pragma once
class TraversePath
{
public:
	TraversePath();

	//! Moves the player linearly from one cell to the next
	void TraversePath::LinearMovement(int currentX, int currentY, int nextX, int nextY);


	~TraversePath();
};

