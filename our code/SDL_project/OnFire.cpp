#include "stdafx.h"
#include "OnFire.h"


OnFire::OnFire()
{
}

OnFire::~OnFire()
{
}

void OnFire::update(Character& character, Grid grid, const Uint8* keyboardState)
{
	character.reactToFire();
	//TODO: make sure character doesn't keep bumping into fire from wandering state
}
