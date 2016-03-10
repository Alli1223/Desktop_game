#pragma once

#include "Texture.h"

class Cell
{
public:
	Cell();
	~Cell();

	int getCellSize() { return cellSize; }

	bool isRoom;

	int getX() { return x; }
	int getY() { return y; }
	int setX(int newX) { return x = newX; }
	int setY(int newY) { return y = newY; }


private:
	int cellSize = 50;
	Texture* sprite;
	//int x, y;
	int x;
	int y;
};