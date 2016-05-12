#include "stdafx.h"
#include "Map.h"

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

				else if (map[x][y] == 'D')
				{
					room.grid[x][y]->isDoor = true;
					room.grid[x][y]->isRoom = false;
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

int roundToNearestWhole(double number) 
{
	if (number + 0.5 >= int(number) + 1)
	{
		return int(number) + 1;
	}
	else
	{
		return int(number);
	}
}

bool Map::generateRoom(Grid level, int size, int entranceX, int entranceY, char direction)  //Direction n = north, e = east, s = south, w = west.
{
	std::vector<std::vector<std::shared_ptr<Cell>>> room;
	double topLeftX;
	double topLeftY;
	if (direction == 'n')
	{
		topLeftX = roundToNearestWhole(entranceX - size / 2);
		topLeftY = entranceY - size - 1;
	}
	else if (direction == 's')
	{
		topLeftX = roundToNearestWhole(entranceX - size / 2);
		topLeftY = entranceY + 1;
	}


		for (int x = topLeftX; x < topLeftX + size; x++)
		{
			if (x < 0 || x > level.grid.size())   										    //Detects if the room goes out the level horizontally
			{
				return false;
			}
			std::vector<std::shared_ptr<Cell>> column;
			for (int y = topLeftY; y < topLeftY + size; y++)
			{
				if (y < 0 || y > level.grid[0].size())								//Detects if the room goes out the level vertically
				{
					return false;
				}
				level.grid[x][y]->isRoom = true;
				column.push_back(level.grid[x][y]);
			}
			room.push_back(column);
		}
		roomVector.push_back(room);
		return true;
}

void Map::generateMap(Grid level)
{
	//Clear a starting room(room 0)
	//generateRoom(level, 5, 2, -1, 's');

	generateRoom(level, 5, 2, 6, 'n');

	int direction = 1;// random(0, 4);
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
