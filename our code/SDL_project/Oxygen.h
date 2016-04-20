#pragma once
class Oxygen
{
public:
	Oxygen();
	~Oxygen();

	int Get_Oxygen_Level() { return Oxygen_Level; }
	int Set_Oxygen_Level(int new_Oxygen_Level) { return Oxygen_Level = new_Oxygen_Level; }

	void spawnOxygen(int x, int y);
	void removeOxygen();

private:
	int Oxygen_Level;
	
};