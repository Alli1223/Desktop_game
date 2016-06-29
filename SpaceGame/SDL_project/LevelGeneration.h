#pragma once
#include "Cell.h"
//#include "Map.h"

//! This class generates the base of the level 
/*!
This class creates a vector of vector of shared pointers to cells
*/

class LevelGeneration
{
public:
	//! A constructor
	LevelGeneration(int WINDOW_WIDTH, int WINDOW_HEIGHT);
	//! A deconstructor 
	~LevelGeneration();

	//! Return the cellSize
	int getCellSize() { return cellSize; }
	//! The base grid that contains the cells
	std::vector<std::vector<std::shared_ptr<Cell>>> grid;
	//! Fills grid with vectors of shared pointers to cells
	void makeGrid(int Window_Width, int Window_Height);


protected:
	//! The size that the cell will be rendered at
	int cellSize = 25;
};

