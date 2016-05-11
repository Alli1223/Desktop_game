#pragma once
#include "Grid.h"
#include "Coordinates.h"



class Oxygen
{
public:
	Oxygen();
	~Oxygen();
	
	std::vector<std::shared_ptr<Coordinates>> getSurroundingCells(int cellSize);

	void update();

	void spawnOxygen(int cellX, int cellY, int cellSize, Grid grid);
	//void removeOxygen(int x, int y);
	int cellX, cellY;
};