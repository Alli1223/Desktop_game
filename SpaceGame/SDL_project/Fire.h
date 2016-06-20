#pragma once
#include "Level.h"
class Fire
{
public:
	Fire();
	~Fire();

	void fireSpread(Level grid, int cellX, int cellY);

	void spawn(Level grid, int cellX, int cellY);

private:
	int fireSpawnChance = 60;
};

