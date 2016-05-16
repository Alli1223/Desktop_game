#pragma once

#include "Texture.h"

class Cell
{
public:
	Cell();
	Cell(int x, int y);
	~Cell();
	
	bool isRoom = false;  //Whether the cell is part of a room or not
	bool isDoor = false;
	int oxygenLevel = 100;


	int getX() { return x; }
	int getY() { return y; }
	int setX(int newX) { return x = newX; }
	int setY(int newY) { return y = newY; }

	bool isOxygenated = false;
	int getOxygenLevel() { return oxygenLevel; }
	int setOxygenLevel(int newOxygenLevel) { return oxygenLevel = newOxygenLevel; }

private:

	Texture* sprite;
	int x = 0, y = 0;

};