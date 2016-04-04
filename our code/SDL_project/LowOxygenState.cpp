#include "stdafx.h"
#include "LowOxygenState.h"


LowOxygenState::LowOxygenState()
{
}


LowOxygenState::~LowOxygenState()
{
}

void LowOxygenState::update(Character& character, Grid grid)
{
	count = count + 1;
}
