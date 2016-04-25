#pragma once
#include "Cell.h"

class Oxygen
{
public:
	Oxygen();
	~Oxygen();

	int Get_Oxygen_Level() { return Oxygen_Level; }
	int Set_Oxygen_Level(int new_Oxygen_Level) { return Oxygen_Level = new_Oxygen_Level; }

	void spawnOxygen(int x, int y, int cell_X, int cell_Y, Cell cell);
	void removeOxygen(int x, int y);

private:
	int Oxygen_Level = 0;
	
};