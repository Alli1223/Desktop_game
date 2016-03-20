#pragma once

#include "Texture.h"

class Cell
{
public:
	Cell();
	~Cell();
	
	bool isRoom;  //Whether the cell is part of a room or not

	int getX() { return x; }
	int getY() { return y; }
	int setX(int newX) { return x = newX; }
	int setY(int newY) { return y = newY; }

	//cell min & max range


private:

	Texture* sprite;
	int x, y;

};