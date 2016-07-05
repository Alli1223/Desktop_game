#pragma once
#include "Level.h"
class ObjectiveManager
{
public:
	ObjectiveManager();
	~ObjectiveManager();

	void ObjectiveManager::RetrieveCrateObjective(Level& level);
	void ObjectiveManager::SpawnObjective(Level& level);

	bool thereIsAGoal = false;
};

