#include "stdafx.h"
#include "RoomDesign.h"
#include "Map.h"


RoomDesign::RoomDesign()
{
}


RoomDesign::~RoomDesign()
{
}

void RoomDesign::designRoom(Level& room, int cellX, int cellY)
{

	
	//RoomDesign::checkCenterCell(room, cellX, cellY);


	
	if (cellX +1 <= room.grid.size() && cellX -1 >= 0 && cellY +1 <= room.grid.size() && cellY -1 >= 0)
	{
		//top
		if (room.grid[cellX][cellY]->isRoom)
		{
			if (room.grid[cellX + 1][cellY]->isRoom)
			{
				if (room.grid[cellX - 1][cellY]->isRoom)
				{
					if (!room.grid[cellX][cellY - 1]->isRoom)
					{
						room.grid[cellX][cellY]->cellOrientation = 1;
					}
				}
			}
		}




		//top and right
		if (room.grid[cellX][cellY]->isRoom)
		{
			if (!room.grid[cellX + 1][cellY]->isRoom)
			{
				if (!room.grid[cellX][cellY - 1]->isRoom)
				{
					if(room.grid[cellX][cellY + 1]->isRoom)
					{
							room.grid[cellX][cellY]->isHullBreach = true;
							
					}
				}
			}
			
		}
	}

		//right

		//right and bottom

		//bottom

		//bottom and left

		//left

		//left and top

		//center
}


bool RoomDesign::checkCenterCell(Level& room, int cellX, int cellY)
{
	std::vector<int> directions;

	directions.push_back(-1);
	directions.push_back(0);
	directions.push_back(1);

	
	for (int x = 1; x >= -1; x--)
	{
		for (int y = -1; y <= 1; y++)
		{
			//is within the map
			if (cellX + (x)+1 <= room.grid.size() && cellX + ((x) +  (-1)) >= 0 && cellY + (y) +1 <= room.grid.size() && cellY + ((y) + (-1)) >= 0)
			{
				//is a room and not a door
				if (room.grid[cellX + x][cellY + y]->isRoom && !room.grid[cellX + x][cellY + y]->isDoor)
				{
					
					if (room.grid[cellX + x][cellY + y]->isRoom && !room.grid[cellX][cellY]->isRoom)
					{
						room.grid[cellX + x][cellY + y]->isHullBreach = true;
						return true;
					}
				}
			}
		}
	}
}
