#pragma once
#include "Grid.h"
#include "Cell.h"

class Oxygen
{
public:
	Oxygen();
	~Oxygen();

	std::vector<std::shared_ptr<Cell>> getNeighbouringCells(int cellSize);
	void disperseOxygen(int cellSize, int oxygenLevel);

	void update(int cellSize, Grid grid);

	void addOxygen(int mouseX, int mouseY, int cellSize, Grid grid);
	void removeOxygen(int mouseX, int mouseY, int cellSize, Grid grid);

	int cellX, cellY;
};