#include "stdafx.h"
#include "ObjectiveManager.h"


ObjectiveManager::ObjectiveManager()
{
}


ObjectiveManager::~ObjectiveManager()
{
}


void ObjectiveManager::SpawnObjective(Level& level)
{
	RetrieveCrateObjective(level);
}

void ObjectiveManager::RetrieveCrateObjective(Level& level)
{
	
	if (thereIsAGoal == false)
	{
		int randomCellX = rand() & 0 + level.grid.size() - 1;
		int randomCellY = rand() & 0 + level.grid.size() - 1;
		if (level.grid[randomCellX][randomCellY]->isRoom && !level.grid[randomCellX][randomCellY]->isOpenDoor)
		{
			level.grid[randomCellX][randomCellY]->isGoal = true;
			thereIsAGoal = true;
		}
	}
	
}