#pragma once
#include "Level.h"
#include "Character.h"
class DoorController
{
public:
	DoorController();
	~DoorController();

	void DoorController::OpenDoor(Level& grid, int cellX, int cellY, Character& character);


	//!Get door status
	bool getDoorStatus() { return doorStatus; }

	//!Set door status
	bool setDoorStatus(bool newDoorStatus) { return doorStatus = newDoorStatus; }

private:
	//!Door status - True is open - False is closed
	bool doorStatus = false;
};

