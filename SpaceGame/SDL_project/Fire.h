#pragma once
#include "Level.h"
class Fire
{
public:
	Fire();
	~Fire();
	//! Determines how the fire will spread
	void fireSpread(Level& grid, int cellX, int cellY);

	//! Spawns the fire at level start
	void spawn(Level& grid, int cellX, int cellY);

private:
	

	//! Controlls how fast the oxygen will spread
	int spawnRate = 10;
};

