#include "stdafx.h"
#include "Map.h"

/*
 TODO:Get the map from file and loads it into the grid system
*/
/*
Map::Map(const std::string& filename)
{
	std::ifstream mapFile(filename);
	const char* MAP_FILE = "Resources\\Map\\test_map.txt";

	map = new Map(MAP_FILE);
	std::vector<std::string> lines;
	while (!mapFile.eof())
	{
		std::string line;
		std::getline(mapFile, line);

		//set the width to the width of the screen
		if (line.length() > width)
		{
			width = line.length();
		}
	}

	//set the height to the ammount of columns in the text file
	height = lines.size();

	//loop through the rows in the text file
	for (int x = 0; x < height; x++)
	{
		std::string& line = lines[x];

		//loop through the columns in the text file
		for (int y = 0; y < height; y++)
		{
			char Character;
			if (x < line.length())
				Character = line[x];
			else
				Character = ' ';

			//Sets Cell_Value based on the chars in the text file
			switch (Character)
			{
			case '#':
				Cell_Value = 1;
				break;
			case '|':
				Cell_Value = 2;
				break;
			default:
				Cell_Value = 0;
			}
		}
	}

	if (map)
		delete map;
}
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
			}
			//closes off smaller levels
			else
			{
				room.grid[x][y]->isRoom = false;
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
