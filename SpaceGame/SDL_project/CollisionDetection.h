#pragma once
class CollisionDetection
	// To stop character rendering slightly outside room
	// To stop character only losing health or winning when it's centre is in the right place
	// To stop multiple character colliding
{
public:
	CollisionDetection();
	~CollisionDetection();

	void checkForIntersect();
	// make list of cells around character that need checking
	// check how close other characters/objects are
	// for loop going though lists and checking for collision
};

