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
	//! Sets the time variables
	unsigned int lastTime = 0, currentTime;

	//! time in seconds that fire will spawn
	int firespawntimer = 1;
private:
	
	int initialFireSpawnNumber = 90000;
	//! Controlls how fast the oxygen will spread
	int spawnRate = 10;
};

