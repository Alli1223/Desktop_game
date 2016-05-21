#pragma once
#include"Character.h"
class KeyboardInput
{
public:
	KeyboardInput();
	~KeyboardInput();
	
	const SDL_Scancode DEFAULT_UP = SDL_SCANCODE_W;
	const SDL_Scancode DEFAULT_DOWN = SDL_SCANCODE_S;
	const SDL_Scancode DEFAULT_LEFT = SDL_SCANCODE_A;
	const SDL_Scancode DEFAULT_RIGHT = SDL_SCANCODE_D;

	const SDL_Scancode ALTERNATE_UP = SDL_SCANCODE_UP;
	const SDL_Scancode ALTERNATE_DOWN = SDL_SCANCODE_DOWN;
	const SDL_Scancode ALTERNATE_LEFT = SDL_SCANCODE_LEFT;
	const SDL_Scancode ALTERNATE_RIGHT = SDL_SCANCODE_RIGHT;

	bool validKeyPress(Character& character, const SDL_Scancode keyboardState);
};

