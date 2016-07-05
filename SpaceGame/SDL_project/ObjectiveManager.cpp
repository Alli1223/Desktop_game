#include "stdafx.h"
#include "ObjectiveManager.h"


ObjectiveManager::ObjectiveManager()
{
}


ObjectiveManager::~ObjectiveManager()
{
}


void ObjectiveManager::SpawnObjective(Level& level, Character& npc)
{
	RetrieveCrateObjective(level, npc);
}

void ObjectiveManager::RetrieveCrateObjective(Level& level, Character& npc)
{
	
	if (thereIsAGoal == false)
	{
		int randomCellX = rand() & 0 + level.grid.size() - 1;
		int randomCellY = rand() & 0 + level.grid.size() - 1;
		if (level.grid[randomCellX][randomCellY]->isRoom && !level.grid[randomCellX][randomCellY]->isOpenDoor)
		{
			level.grid[randomCellX][randomCellY]->isGoal = true;
			thereIsAGoal = true;
			
			GoalPoint = Point(randomCellX, randomCellY);
			
		}
	}

	if (npc.getX() / level.getCellSize() == GoalPoint.getX() && npc.getY() / level.getCellSize() == GoalPoint.getY())
	{
		//set the goal as the spawn
		
		npc.hasObjective = true;
		GoalPoint = Point(1, 1);

		//Drop off the objective
		if (npc.getX() / level.getCellSize() == 1 && npc.getY() / level.getCellSize() == 1)
		{
			npc.hasObjective = false;
		}
	}

}