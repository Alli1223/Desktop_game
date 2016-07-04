#pragma once
class GameSettings
{
public:
	GameSettings();
	~GameSettings();

	//! int that will be used to control movement speed
	const int FRAME_RATE = 60;

	int WINDOW_WIDTH = 800;
	int WINDOW_HEIGHT = 600;

	bool fullscreen = false;

	// Will be WASD/default movement
	SDL_Scancode DEFAULT_UP = SDL_SCANCODE_W;
	SDL_Scancode DEFAULT_DOWN = SDL_SCANCODE_S;
	SDL_Scancode DEFAULT_LEFT = SDL_SCANCODE_A;
	SDL_Scancode DEFAULT_RIGHT = SDL_SCANCODE_D;

	//Alternate movement keys will be customisable
	SDL_Scancode ALTERNATE_UP = SDL_SCANCODE_UP;
	SDL_Scancode ALTERNATE_DOWN = SDL_SCANCODE_DOWN;
	SDL_Scancode ALTERNATE_LEFT = SDL_SCANCODE_LEFT;
	SDL_Scancode ALTERNATE_RIGHT = SDL_SCANCODE_RIGHT;
};

