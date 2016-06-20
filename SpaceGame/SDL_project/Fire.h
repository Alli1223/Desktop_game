#pragma once
class Fire
{
public:
	Fire();
	~Fire();
	void update();

	void spawn();

private:
	int fireSpawnChance = 60;
};

