#pragma once
class GameConfig
{
public:
	GameConfig();
	~GameConfig();

private:
	const int FRAME_RATE = 60;

	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 800;

	int DEAFULT_UP;
	int DEAFULT_DOWN;
	int DEFAULT_LEFT;
	int DEFAULT_RIGHT;

	int ALTERNATE_UP;
	int ALTERNATE_DOWN;
	int ALTERNATE_LEFT;
	int ALTERNATE_RIGHT;
};

