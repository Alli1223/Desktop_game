#pragma once
class Cell
{
public:
	Cell();
	~Cell();

	int getCellSize() { return cellSize; }

private:
	int cellSize = 10;
};

