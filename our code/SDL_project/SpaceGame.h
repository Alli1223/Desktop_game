#pragma once

#include "Texture.h"


class SpaceGame
{
public:
	SpaceGame();
	~SpaceGame();

	void run();
	
	static const int WINDOW_WIDTH = 800;
	static const int WINDOW_HEIGHT = 800;

private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	Texture cellSprite;
	Texture cellSprite2;
	Texture characterTex;

	bool running;

};

