#include "stdafx.h"
#include "Map.h"

/*
 TODO:Get the map from file and loads it into the grid system
*/

void Map::LoadMap(std::string filename, Grid room)
//(filename, grid to load into) loads map from text file into grid
{
	//loop through the file
	std::ifstream mapFile(filename);
	std::vector<std::string> map;
	while (!mapFile.eof())
	{
		//make a vector containing all the lines in the file
		std::string line;
		std::getline(mapFile, line);
		map.push_back(line);
	}
	//loop through the cells on display
	for (int x = 0; x < room.grid.size(); x++)
	{
		for (int y = 0; y < room.grid[0].size(); y++)
		{
			//checks if the character exhists
			if (x < map.size() && y < map[x].size())
			{
				//checks if the character is a wall
				if (map[x][y] == '#')
				{
					room.grid[x][y]->isRoom = false;
				}
				else
				{
					room.grid[x][y]->isRoom = true;
				}
			}
			//closes off smaller levels
			else
			{
				room.grid[x][y]->isRoom = false;
			}
		}
	}
}

int Map::random(int smallestValue, int largestValue)
{
	std::srand(time(nullptr));
	return (rand() % (largestValue - smallestValue)) + smallestValue;
}

void Map::generateMap(Grid level)
{
	std::vector<std::vector<std::vector<std::shared_ptr<Cell>>>> roomVector;
	std::vector<std::vector<std::shared_ptr<Cell>>> room;
	//Clear a starting room(room 0)
	for (int x = 0; x < 4; x++)
	{
		std::vector<std::shared_ptr<Cell>> column;
		for (int y = 0; y < 4; y++)
		{
			level.grid[x][y]->isRoom = true;
			column.push_back(level.grid[x][y]);
		}
		room.push_back(column);
	}
	roomVector.push_back(room);
	int direction = random(0, 4);
	if (direction == 0)																//north
	{
		if (roomVector[0][0][0]->getY() - 1 > 0)
		{
			int yOfDoor = roomVector[0][0][0]->getY() - 1;
			int xStart = roomVector[0][0][0]->getX();
			int halfRoomSize = roomVector[0].size() / 2;
			int xOfDoor = xStart + halfRoomSize;
			if (level.grid[xOfDoor][yOfDoor]->isRoom == false)
			{
				level.grid[xOfDoor][yOfDoor]->isRoom = true;
				level.grid[xOfDoor][yOfDoor]->isDoor = true;
			}
		}

	}
	if (direction == 1)																//east
	{
		if (roomVector[0][0][0]->getX() + 1 < level.grid.size())
		{
			int xSize = roomVector[0].size();
			int xOfDoor = roomVector[0][0][0]->getX() + xSize;
			int yStart = roomVector[0][0][0]->getY();
			int halfRoomSize = roomVector[0][0].size() / 2;
			int yOfDoor = yStart + halfRoomSize;
			if (level.grid[xOfDoor][yOfDoor]->isRoom == false)
			{
				level.grid[xOfDoor][yOfDoor]->isRoom = true;
				level.grid[xOfDoor][yOfDoor]->isDoor = true;
			}
		}

	}

}

Map::Map()
{
}

Map::~Map()
{
}
