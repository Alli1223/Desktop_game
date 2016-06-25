#include "stdafx.h"
#include "LevelGeneration.h"
#include "Oxygen.h"


// Populates a 2 dimentional vector with pointers to cells
void LevelGeneration::makeGrid(int windowWidth, int windowHeight)
{
	// Calculate the number of cells on each axis
	int XAxis_Max = windowWidth / cellSize;
	int YAxis_Max = windowHeight / cellSize;

	for (int x = 0; x < XAxis_Max; x++)
	{
		// Pushes back a column into the row
		std::vector<std::shared_ptr<Cell>> column;
		grid.push_back(column);
		for (int y = 0; y < YAxis_Max; y++)
		{
			// Populates the column with pointers to cells
			Cell cell(x,y);
			cell.isRoom = false;
			auto sharedCell = std::make_shared<Cell> (cell);
			grid[x].push_back(sharedCell);
		}
	}
}

LevelGeneration::LevelGeneration(int WINDOW_WIDTH, int WINDOW_HEIGHT)
{
	//Creates an empty grid of cells
	makeGrid(WINDOW_WIDTH, WINDOW_HEIGHT);

}


LevelGeneration::~LevelGeneration()
{
}
