#pragma once
#include "Level.h"
class Fire
{
public:
	Fire();
	~Fire();

	void update(Level grid, int cellX, int cellY);

	void spawn();

private:
	int fireSpawnChance = 60;
};

