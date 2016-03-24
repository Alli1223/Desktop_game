#include "stdafx.h"
#include "SpaceGame.h"
#include "InitialisationError.h"
#include "Cell.h"
#include "Grid.h"
#include "MainCharacter.h"


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

bool SpaceGame::getCellState(int x, int y, int cellSize, std::vector<std::vector<std::shared_ptr<Cell>>> grid)
{ //Currently checks to see if a cell is part of a room or not
	int xCell = x / cellSize;
	int yCell = y / cellSize;
	bool state = grid[xCell][yCell]->isRoom; //Access violation error
	return state;
}

void SpaceGame::run()
{
	Grid room;
	
	room.makeGrid(WINDOW_WIDTH, WINDOW_HEIGHT);
	MainCharacter characterOne;
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
		}//End pollevent if

		//checks keyboard state then updates character
		const Uint8* keyboardState = SDL_GetKeyboardState(nullptr);
		if (keyboardState[SDL_SCANCODE_UP] || keyboardState[SDL_SCANCODE_W])
			characterOne.update("up");
		else if (keyboardState[SDL_SCANCODE_DOWN] || keyboardState[SDL_SCANCODE_S])
			characterOne.update("down");
		else if (keyboardState[SDL_SCANCODE_LEFT] || keyboardState[SDL_SCANCODE_A])
			characterOne.update("left");
		else if (keyboardState[SDL_SCANCODE_RIGHT] || keyboardState[SDL_SCANCODE_D])
			characterOne.update("right");
		
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
			} //End for Y loop
		
			//cellSprite.render(renderer, room.grid[i].getX() * cellSize + cellSize / 2, room.grid[i].getY() * cellSize + cellSize / 2, cellSize, cellSize);
			
			
		}//End for X loop

		characterTex.render(renderer, characterOne.getX(), characterOne.getY(), characterOne.getSize(), characterOne.getSize());
		
		bool roomState = getCellState(characterOne.getX(), characterOne.getY(), characterOne.getSize(), room.grid);
		// Present the rendered display
		SDL_RenderPresent(renderer);
	}//End while running

}
