#pragma once
#include "Character.h"
#include "Point.h"
class TraversePath
{
public:
	TraversePath();

	//! Moves the player linearly from one cell to the next
	void TraversePath::LinearMovement(Character& characterOne, Point point);

	void TraversePath::seekNextNode(Character& characterOne, Point point);

	Point TraversePath::getNextPoint(std::vector<Point> path);

	void TraversePath::VerticalMovement(Character& characterOne, Point point);

	void TraversePath::HorizontalMovement(Character& characterOne, Point point);

	Point previousPoint;
	int pathPointIterator = 0;

	~TraversePath();
private:
	
};

