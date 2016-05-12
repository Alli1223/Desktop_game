#include "stdafx.h"
#include "SpaceGame.h"
#include "InitialisationError.h"
#include "Cell.h"
#include "Grid.h"
#include "MainCharacter.h"
#include "IdleState.h"
#include "Oxygen.h"


SpaceGame::SpaceGame()
	: notRoomCell("Resources\\cell_test.png"),
	roomCell("Resources\\Room_Cell1.png"),
	characterTex("Resources\\crew2.png"),
	doorTexture("Resources\\door_sprite.png"),
	oxygenTex("Resources\\oxygen.png"),
	fire("Resources\\fire.png"),
	healthBar("Resources\\health.png"),
	healthText("Resources\\healthText.png"),
	oxygenBar("Resources\\oxygenBar.png"),
	oxygenText("Resources\\oxygenText.png")
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
	Oxygen oxygen;
	room.makeGrid(WINDOW_WIDTH, WINDOW_HEIGHT);
	Map mapLoader;
	mapLoader.LoadMap("Resources\\Map\\test_map.txt", room);
	MainCharacter characterOne;
	//Character needs a pointer to the room to get the state
	characterOne.currentRoom = std::make_shared<Grid>(room);
	//Character starts in Idle state
	characterOne.state = std::make_shared<IdleState>();

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

		// Checks the keyboard for input
		const Uint8* keyboardState = SDL_GetKeyboardState(nullptr);
		// Checks and updates the character state
		characterOne.state->update(characterOne, keyboardState);
		
		// Rendering process:
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		int cellSize = room.getCellSize();

		//Spawns oxygen
		int mouse_X, mouse_Y;
		if (SDL_GetMouseState(&mouse_X, &mouse_Y) & SDL_BUTTON(SDL_BUTTON_LEFT))
		{
			oxygen.addOxygen(mouse_X, mouse_Y, cellSize, room);
		}

		else if (SDL_GetMouseState(&mouse_X, &mouse_Y) & SDL_BUTTON(SDL_BUTTON_RIGHT))
		{
			oxygen.removeOxygen(mouse_X, mouse_Y, cellSize, room);
		}
		
		for (int x = 0; x < room.grid.size(); x++)
		{
			for (int y = 0; y < room.grid[x].size(); y++)
			{
				int xPos = x * cellSize + cellSize / 2;
				int yPos = y * cellSize + cellSize / 2;
				if (y > 6)
				{
					room.grid[x][y]->onFire = true;
				}

				//Renders cell based on state
				if (room.grid[x][y]->isRoom)//Detects if the cell is a room
				{
					roomCell.render(renderer, xPos, yPos, cellSize, cellSize);
					oxygenTex.render(renderer, xPos, yPos, cellSize, cellSize);
					oxygenTex.addTransparency(room.grid[x][y]->oxygenLevel);
					if (room.grid[x][y]->onFire)
						fire.render(renderer, xPos, yPos, cellSize, cellSize);
				}
				if (room.grid[x][y]->isDoor)//Detects if the cell is a door
				{
					doorTexture.render(renderer, xPos, yPos, cellSize, cellSize);
					oxygenTex.render(renderer, xPos, yPos, cellSize, cellSize);
					oxygenTex.addTransparency(room.grid[x][y]->oxygenLevel);
				}

				//Doesn't render a cell if it isn't part of a room

	
			} //End for Y loop
			
		}//End for X loop

		//Need to render character based on state 
		
		characterTex.render(renderer, characterOne.getX(), characterOne.getY(), characterOne.getSize(), characterOne.getSize());
		
		//Renders the health and oxygen bar
		healthBar.render(renderer, WINDOW_WIDTH , 25, characterOne.health * 10, 25);
		healthText.render(renderer, 750, 25, 73, 22);
		oxygenBar.render(renderer, WINDOW_WIDTH, 50, 1000, 25);
		oxygenText.render(renderer, 750, 50, 73, 22);
		
		SDL_RenderPresent(renderer);
	}//End while running

}
