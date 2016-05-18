#pragma once
#include "Level.h"
#include "Cell.h"

class Oxygen
{
public:
	Oxygen();
	~Oxygen();

	std::vector<std::shared_ptr<Cell>> getNeighbouringCells(int cellSize);
	void disperseOxygen(int cellSize, int oxygenLevel);

	void update(int cellSize, Grid grid);
	void addOxygen(int mouseX, int mouseY, int cellSize, Level grid);
	void removeOxygen(int mouseX, int mouseY, int cellSize, Level grid);

	int cellX, cellY;
};