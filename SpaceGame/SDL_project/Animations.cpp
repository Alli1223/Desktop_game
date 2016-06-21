#include "stdafx.h"
#include "Animations.h"


Animations::Animations()
{
}


Animations::~Animations()
{
}

void Animations::DeathAnimation(SpaceGame& spaceGame)
{
	Uint32 ticks = SDL_GetTicks();
	Uint32 seconds = ticks / 1000;
	Uint32 sprite = seconds % 4;
	SDL_Rect srcrect = { sprite * 32, 0, 32, 64 };
}
