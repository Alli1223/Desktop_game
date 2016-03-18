#include "stdafx.h"
#include "SpaceGame.h"
#include "InitialisationError.h"
#include "Cell.h"
#include "Grid.h"
#include "Character.h"


SpaceGame::SpaceGame()
	: cellSprite("Resources\\cell_test.png"), 
	cellSprite2("Resources\\cell_test2.png"),
	characterTex("Resources\\char.png")
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		throw InitialisationError("SDL_Init failed");

	}

	window = SDL_CreateWindow("COMP150 Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == nullptr)
	{
		throw InitialisationError("SDL_CreateWindow failed");
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr)
	{
		throw InitialisationError("SDL_CreateRenderer failed");
	}
}


SpaceGame::~SpaceGame()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void SpaceGame::run()
{
	

	Grid room;
	Character character;
	room.makeGrid(WINDOW_WIDTH, WINDOW_HEIGHT);

	running = true;
	while (running)
	{
		// Handle events
		SDL_Event ev;
		if (SDL_PollEvent(&ev))
		{
			switch (ev.type)
			{
			case SDL_QUIT:
				running = false;
				break;

			default:
				break;
			}
		}


		character.update();
		//SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		int cellSize = room.getCellSize();
		
		for (int x = 0; x < room.grid.size(); x++)
		{
			for (int y = 0; y < room.grid[x].size(); y++)
			{
				int xPos = x * cellSize + cellSize / 2;
				int yPos = y * cellSize + cellSize / 2;
				cellSprite.render(renderer, xPos, yPos, cellSize, cellSize);
			}
		
			//cellSprite.render(renderer, room.grid[i].getX() * cellSize + cellSize / 2, room.grid[i].getY() * cellSize + cellSize / 2, cellSize, cellSize);
			
			
		}//End for loop

		characterTex.render(renderer, character.getX(), character.getY(), character.getSize(), character.getSize());
		

		// Present the rendered display
		SDL_RenderPresent(renderer);
	}

}
