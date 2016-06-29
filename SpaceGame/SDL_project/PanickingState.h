#pragma once
#include "CharacterState.h"

//!  The panickingState class is used to make the character "panic"
/*!
*/
class PanickingState :
	public CharacterState
{
public:
	PanickingState();
	~PanickingState();

	// TODO: Characters run from fire
	//		Panicking will use up oxygen faster
};

