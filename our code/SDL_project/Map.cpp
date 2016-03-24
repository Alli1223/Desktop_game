#include "stdafx.h"
#include "Map.h"
/*
 TODO:Get the map from file and loads it into the grid system
*/

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

		//set the width to the ammount of chars in the text files row
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


Map::~Map()
{

}