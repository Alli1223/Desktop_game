#pragma once
#include "Grid.h"
#include "Cell.h"

class Oxygen
{
public:
	Oxygen();
	~Oxygen();

	std::vector<std::shared_ptr<Cell>> getNeighbouringCells(int cellX, int cellY, int cellSize);

	void update(int cellSize, int cellX, int cellY, Grid grid);

	void addOxygen(int mouseX, int mouseY, int cellSize, Grid grid);
	void removeOxygen(int mouseX, int mouseY, int cellSize, Grid grid);

	int cellX, cellY;
};