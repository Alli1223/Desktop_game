#pragma once
class Cell
{
public:
	Cell();
	~Cell();

	int getCellSize() { return cellSize; }

	bool isRoom;


private:
	int cellSize = 10;
};

