#pragma once
#include "Grid.h"
#include "Cell.h"

class Oxygen
{
public:
	Oxygen();
	~Oxygen();

	std::vector<std::shared_ptr<Cell>> getNeighbouringCells(int cellSize);

	void update(int cellSize);

	void addOxygen(int mouseX, int mouseY, int cellSize, Grid grid);
	void removeOxygen(int mouseX, int mouseY, int cellSize, Grid grid);

	int cellX, cellY;
};