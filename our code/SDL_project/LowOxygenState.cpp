#include "stdafx.h"
#include "LowOxygenState.h"


LowOxygenState::LowOxygenState()
{
	count = 3;
}


LowOxygenState::~LowOxygenState()
{
}

void LowOxygenState::update(Character& character, Grid grid)
{
	character.setSpeed(1);  //Will change to a variable and use framerate
	count = 1;
	if (character.oxygenLevel > 50)
	{
		character.state = std::make_shared<IdleState>();
		character.setSpeed(2);
		count = 1;
	}
}