#include "stdafx.h"
#include "Cell.h"


Cell::Cell()
	: sprite(sprite)
{
}
Cell::Cell(int x, int y)
{
	setX(x);
	setY(y);
}

Cell::~Cell(){
}