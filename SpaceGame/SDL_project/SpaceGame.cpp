#include "stdafx.h"
#include "SpaceGame.h"
#include "InitialisationError.h"
#include "Cell.h"
#include "Level.h"
#include "MainCharacter.h"
#include "IdleState.h"
#include "Oxygen.h"
#include "Fire.h"
#include "RoomDesign.h"

SpaceGame::SpaceGame()
	: roomCell("Resources\\Room_Cell1.png"),
	characterTex("Resources\\crew2.png"),
	doorTexture("Resources\\door_sprite.png"),
	oxygenTex("Resources\\oxygen.png"),
	healthBar("Resources\\health.png"),
	healthText("Resources\\healthText.png"),
	winTexture("Resources\\oxygenBar.png"),
	winText("Resources\\you_win.png"),
	oxygenBar("Resources\\oxygenBar.png"),
	oxygenText("Resources\\oxygenText.png"),
	gameOver("Resources\\health.png"),
	gameOverText("Resources\\game_over.png"),
	fireTexture("Resources\\fire2.png"),
	backgroundTexture("Resources\\background1.png"),
	hullBreachTexture("Resources\\RoomCell_Oxygen.png"),
	goalTexture("Resources\\goal.png"){
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
	// Level generation
	Level room;
	room.makeGrid(WINDOW_WIDTH, WINDOW_HEIGHT);
	Map mapLoader;

	//mapLoader.LoadMap("Resources\\test_map.txt", room);
	mapLoader.generateMap(room);
	
	Oxygen oxygen;
	Fire fire;
	RoomDesign designroom;
	
	MainCharacter characterOne;
	//Character needs a pointer to the room to get the state
	characterOne.currentRoom = std::make_shared<Level>(room);
	//Character starts in Idle state
	characterOne.state = std::make_shared<IdleState>();
	characterOne.windowHeight = WINDOW_HEIGHT;
	characterOne.windowWidth= WINDOW_WIDTH;

	running = true;
	double timer = 0;

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

		backgroundTexture.render(renderer, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, WINDOW_WIDTH, WINDOW_HEIGHT);

		int cellSize = room.getCellSize();

		// Adds and removes oxygen based on mouse click
		if (SDL_GetMouseState(&mouse_X, &mouse_Y) & SDL_BUTTON(SDL_BUTTON_LEFT))
		{
			oxygen.addOxygen(mouse_X, mouse_Y, cellSize, room);
		}

		else if (SDL_GetMouseState(&mouse_X, &mouse_Y) & SDL_BUTTON(SDL_BUTTON_RIGHT))
		{
			oxygen.removeOxygen(mouse_X, mouse_Y, cellSize, room);
		}

		// Runs Oxygen spread function
		oxygen.update(room);
		
		
		for (int x = 0; x < room.grid.size(); x++)
		{
			for (int y = 0; y < room.grid.size(); y++)
			{
				int xPos = x * cellSize + cellSize /2;
				int yPos = y * cellSize + cellSize /2;
				
				
				
				// Checks if the cell is a room
				if (room.grid[x][y]->isRoom)
				{
					
					oxygenTex.alterTransparency(room.grid[x][y]->oxygenLevel);
					roomCell.render(renderer, xPos, yPos, cellSize, cellSize);
					oxygenTex.render(renderer, xPos, yPos, cellSize, cellSize);
					
				}
				// Checks if the cell is a door
				if (room.grid[x][y]->isDoor)
				{
					doorTexture.render(renderer, xPos, yPos, cellSize, cellSize);
				}
				//Checks if the cell has the goal on it.
				if (room.grid[x][y]->isGoal)
				{
					oxygenTex.alterTransparency(room.grid[x][y]->oxygenLevel);
					roomCell.render(renderer, xPos, yPos, cellSize, cellSize);
					oxygenTex.render(renderer, xPos, yPos, cellSize, cellSize);
					goalTexture.render(renderer, xPos, yPos, cellSize, cellSize);
				}
				//renders the fire cells
				if (room.grid[x][y]->isOnFire)
				{
					fireTexture.alterTransparency(95);
					roomCell.render(renderer, xPos, yPos, cellSize, cellSize);
					fireTexture.render(renderer, xPos, yPos, cellSize, cellSize);
				}
				// Renders the hullBreach
				if (room.grid[x][y]->isHullBreach)
				{
					roomCell.render(renderer, xPos, yPos, cellSize, cellSize);
					hullBreachTexture.render(renderer, xPos, yPos, cellSize, cellSize);
				}
				// Does not render a cell if it isn't part of a room
			} //End for Y loop
		}//End for X loop

		 // Renders the health and oxygen bar
		healthBar.render(renderer, characterOne.getX(), characterOne.getY() - 40, characterOne.health, 10);
		healthBar.alterTransparency(150);
		healthText.render(renderer, characterOne.getX(), characterOne.getY() - 40, 60, 20);
		oxygenBar.render(renderer, characterOne.getX(), characterOne.getY() - 30, oxygen.getOxygenReserves() / 20, 10);
		oxygenBar.alterTransparency(150);
		oxygenText.render(renderer, characterOne.getX(), characterOne.getY() - 30, 60, 20);

		characterTex.render(renderer, characterOne.getX(), characterOne.getY(), characterOne.getSize(), characterOne.getSize());

		 // If the character has died the game over screen is displayed
		if (!characterOne.isAlive)
		{
			// Fades in a red background
			if (timer < 255)
			{				
				timer++;
				gameOver.alterTransparency(timer);
				gameOver.render(renderer, WINDOW_WIDTH/2, WINDOW_HEIGHT/2, WINDOW_WIDTH, WINDOW_HEIGHT);
			}
			// Displays text
			else if (timer >= 255 && timer < 300)
			{
				timer++;
				gameOver.alterTransparency(255);
				gameOver.render(renderer, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, WINDOW_WIDTH, WINDOW_HEIGHT);
				gameOverText.render(renderer, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, WINDOW_WIDTH, WINDOW_HEIGHT);
				
			}
			//starts a new game
			else
				SpaceGame::run();
		}
		// If the character has reached the end the You Won screen is displayed
		if (characterOne.hasWon)
		{
			// Fades in a blue background
			if (timer < 255)
			{
				timer++;
				winTexture.alterTransparency(timer);
				winTexture.render(renderer, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, WINDOW_WIDTH, WINDOW_HEIGHT);
			}
			// Displays text
			else if(timer >= 255 && timer < 300)
			{
				timer++;
				winTexture.alterTransparency(255);
				winTexture.render(renderer, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, WINDOW_WIDTH, WINDOW_HEIGHT);
				winText.render(renderer, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, WINDOW_WIDTH, WINDOW_HEIGHT);
			}
			else
				SpaceGame::run();
		}
		
		
		SDL_RenderPresent(renderer);
	}// End while running
}
