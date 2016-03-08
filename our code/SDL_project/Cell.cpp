#include "stdafx.h"
#include "Cell.h"


Cell::Cell()
	: sprite(sprite)
{
}


Cell::~Cell()
{
}


void Cell::render(SDL_Renderer* renderer)
{
	sprite->render(renderer, 10, 10, 10, 10);
}


