#pragma once

#include "Texture.h"

class Cell
{
public:
	Cell();
	Cell(int x, int y);
	~Cell();
	
	bool isRoom = true;  //Whether the cell is part of a room or not
	bool isDoor = false;
	bool onFire = false;
	int oxygenLevel = 20;


	int getX() { return x; }
	int getY() { return y; }
	int setX(int newX) { return x = newX; }
	int setY(int newY) { return y = newY; }

	bool isOxygenated = false;
	int getOxygenLevel() { return oxygenLevel; }
	int setOxygenLevel(int newOxygenLevel) { return oxygenLevel = newOxygenLevel; }

private:

	Texture* sprite;
	int x, y;

};