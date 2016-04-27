#pragma once

#include "Texture.h"

class Cell
{
public:
	Cell();
	~Cell();
	
	bool isRoom = true;  //Whether the cell is part of a room or not

	bool isOxygenated = false;
	int get_Oxygen_level() { return oxygen_level; }
	int set_Oxygen_level(int new_oxygen_level) { return oxygen_level = new_oxygen_level; }

	int getX() { return x; }
	int getY() { return y; }
	int setX(int newX) { return x = newX; }
	int setY(int newY) { return y = newY; }

private:

	Texture* sprite;
	int x, y;
	int oxygen_level;

};