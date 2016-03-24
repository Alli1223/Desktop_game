#include "stdafx.h"
#include "MainCharacter.h"


MainCharacter::MainCharacter()
{
}


MainCharacter::~MainCharacter()
{
}


void MainCharacter::update(std::string direction)
{
	if (direction == "up")
		setY(getY() - 1);
	else if (direction == "down")
		setY(getY() + 1);
	else if (direction == "left")
		setX(getX() - 1);
	else if (direction == "right")
		setX(getX() + 1);
}
