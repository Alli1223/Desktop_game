#pragma once
#include "Level.h"
#include "Cell.h"

class Oxygen
{
public:
	Oxygen();
	~Oxygen();

	void update(int cellSize, Level grid);
	void addOxygen(int mouseX, int mouseY, int cellSize, Level grid);
	void removeOxygen(int mouseX, int mouseY, int cellSize, Level grid);

	int getOxygenReserves() { return oxygenReserves; }
	int setOxygenReserves(int newOxygenReserveLevel) { return oxygenReserves = newOxygenReserveLevel; }


	int cellX, cellY;
private:
	int oxygenReserves = 800;
};