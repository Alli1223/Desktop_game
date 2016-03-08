#pragma once

#include "Texture.h"

class Cell
{
public:
	Cell();
	~Cell();

	int getCellSize() { return cellSize; }
	void render(SDL_Renderer* renderer);

	bool isRoom;

	int getX() { return x; }
	int getY() { return y; }

private:
	int cellSize = 100;
	Texture* sprite;
	//int x, y;
	int x = 10;
	int y = 10;
};

