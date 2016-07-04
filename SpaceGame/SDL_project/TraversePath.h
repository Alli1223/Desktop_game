#pragma once
#include "Character.h"
#include "Point.h"
class TraversePath
{
public:
	TraversePath();

	//! Moves the player linearly from one cell to the next
	void TraversePath::LinearMovement(Character& characterOne, Point point);

	bool TraversePath::seekNextNode(Character& characterOne, Point& point);

	Point TraversePath::getNextPoint(std::vector<Point> path);

	int pathPointIterator = 0;

	~TraversePath();
private:
	
};

