#pragma once

#include "Character.h"
#include "Level.h"

class MainCharacter: public Character
{ //The main version of character that user controllers
	//Should only be one instance of this class ??
public:
	MainCharacter();
	~MainCharacter();
};

