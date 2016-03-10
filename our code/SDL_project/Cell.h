#pragma once

#include "Texture.h"

class Cell
{
public:
	Cell();
	~Cell();



	bool isRoom;

	int getX() { return x; }
	int getY() { return y; }
	int setX(int newX) { return x = newX; }
	int setY(int newY) { return y = newY; }


private:

	Texture* sprite;
	//int x, y;
	int x;
	int y;
};