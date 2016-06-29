#pragma once
class GameSettings
{
public:
	GameSettings();
	~GameSettings();

	//! int that will be used to control movement speed
	const int FRAME_RATE = 60;

	int WINDOW_WIDTH = 1000;
	int WINDOW_HEIGHT = 800;

	bool fullscreen = false;

	// Will be WASD/default movement
	int DEAFULT_UP;
	int DEAFULT_DOWN;
	int DEFAULT_LEFT;
	int DEFAULT_RIGHT;

	//Alternate movement keys will be customisable
	int ALTERNATE_UP;
	int ALTERNATE_DOWN;
	int ALTERNATE_LEFT;
	int ALTERNATE_RIGHT;
};

