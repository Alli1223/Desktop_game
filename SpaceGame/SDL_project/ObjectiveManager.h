#pragma once
#include "Level.h"
#include "Point.h"
#include "PathFinder.h"
#include "NPC.h"

class ObjectiveManager
{
public:
	ObjectiveManager();
	~ObjectiveManager();

	void ObjectiveManager::RetrieveCrateObjective(Level& level, Character& npc);
	void ObjectiveManager::SpawnObjective(Level& level, Character& npc);

	Point GoalPoint;
	bool thereIsAGoal = false;
};

