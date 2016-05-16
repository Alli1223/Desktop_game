#pragma once
#include "Level.h"
#include "Cell.h"

class Oxygen
{
public:
	Oxygen();
	~Oxygen();

	std::vector<std::shared_ptr<Cell>> getNeighbouringCells(int cellX, int cellY, int cellSize);

	void update(int cellSize, int cellX, int cellY, Level grid);

	void addOxygen(int mouseX, int mouseY, int cellSize, Level grid);
	void removeOxygen(int mouseX, int mouseY, int cellSize, Level grid);

	int cellX, cellY;
};