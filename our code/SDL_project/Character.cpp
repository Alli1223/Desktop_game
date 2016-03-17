#include "stdafx.h"
#include "Character.h"


Character::Character()
{
}


Character::~Character()
{
}

void Character::update()
{
	setX(getX() + 1);
	setY(getY() + 1);
}
