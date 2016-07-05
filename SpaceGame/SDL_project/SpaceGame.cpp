#include "stdafx.h"
#include "SpaceGame.h"
#include "InitialisationError.h"

SpaceGame::SpaceGame()
	// Texture file locations
	: roomCell("Resources\\roomSprites\\center.png"),
	topRoomCell("Resources\\roomSprites\\top.png"), topRightRoomCell("Resources\\roomSprites\\topRight.png"), rightRoomCell("Resources\\roomSprites\\right.png"), bottomRightRoomCell("Resources\\roomSprites\\bottomRight.png"), bottomRoomCell("Resources\\roomSprites\\bottom.png"), bottomLeftRoomCell("Resources\\roomSprites\\bottomLeft.png"), leftRoomCell("Resources\\roomSprites\\left.png"), topLeftRoomCell("Resources\\roomSprites\\topLeft.png"),
	characterTex("Resources\\crew2.png"), characterLeft("Resources\\Character\\crewLeft.png"), characterRight("Resources\\Character\\crewRight.png"), characterUp("Resources\\Character\\crewUp.png"), characterDown("Resources\\Character\\crewDown.png"),
	npcLeft("Resources\\Character\\npcLeft.png"), npcRight("Resources\\Character\\npcRight.png"), npcUp("Resources\\Character\\npcUp.png"), npcDown("Resources\\Character\\npcDown.png"),
	NpcTex("Resources\\Character\\NPC.png"),
	closedDoorTexture("Resources\\roomSprites\\center.png"),
	openDoorTexture("Resources\\door_sprite.png"),
	oxygenTex("Resources\\oxygen.png"),
	oxygenTank("Resources\\SpawnItems\\oxygenTank.png"), healthPack("Resources\\SpawnItems\\healthPack.png"),
	healthBar("Resources\\health.png"),
	healthText("Resources\\healthText.png"),
	winTexture("Resources\\oxygenBar.png"),
	winText("Resources\\you_win.png"),
	oxygenBar("Resources\\oxygenBar.png"),
	oxygenText("Resources\\oxygenText.png"),
	gameOver("Resources\\health.png"),
	gameOverText("Resources\\game_over.png"),
	fireTexture("Resources\\SpawnItems\\fire1.png"),
	backgroundTexture("Resources\\background.png"),
	hullBreachTexture("Resources\\roomSprites\\hullBreach2.png"),
	deathAnim("Resources\\deathAnim.png"),
	goalTexture("Resources\\roomSprites\\crate1.png"){
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		throw InitialisationError("SDL_Init failed");
	}
	
	window = SDL_CreateWindow("SpaceGame", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE);
	
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
	ItemController doorcontroller;
	MainCharacter characterOne;
	NPC NpcOne;
	Cell cell;
	Pathfinder pathfinder;
	Point point;
	TraversePath traversepath;
	ObjectiveManager objectivemanager;

	//Character needs a pointer to the room to get the state
	characterOne.currentRoom = std::make_shared<Level>(room);
	//Character starts in Idle state
	characterOne.state = std::make_shared<IdleState>();
	characterOne.windowHeight = WINDOW_HEIGHT;
	characterOne.windowWidth = WINDOW_WIDTH;

	running = true;
	unsigned int timer = 0;

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

		// Renders the background image
		backgroundTexture.render(renderer, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, WINDOW_WIDTH, WINDOW_HEIGHT);

		int cellSize = room.getCellSize();

		// Adds and removes oxygen based on mouse click
		if (SDL_GetMouseState(&mouse_X, &mouse_Y) & SDL_BUTTON(SDL_BUTTON_LEFT))
		{
			oxygen.addOxygen(mouse_X, mouse_Y, cellSize, room);
		}

		//Pathfinding function
		else if (SDL_GetMouseState(&mouse_X, &mouse_Y) & SDL_BUTTON(SDL_BUTTON_RIGHT))
		{
			//oxygen.removeOxygen(mouse_X, mouse_Y, cellSize, room);
			
			// set the start and end points
			if (NpcOne.getX() / cellSize >= 1 && NpcOne.getY() / cellSize >= 1)
			{
				startPoint = Point(NpcOne.getX() / cellSize, NpcOne.getY() / cellSize);
				endPoint = objectivemanager.GoalPoint;
			}
			//find path
			path = pathfinder.findPath(room, startPoint, endPoint);
			// Allow the traversepath to start
			traversepath.pathComplete == false;
		}

		//Spawn a random objective for the player to do
		objectivemanager.SpawnObjective(room, NpcOne);
		objectivemanager.NPCRetrieveCrate(room, NpcOne, pathfinder, traversepath);
	

		for (int x = 0; x < room.grid.size(); x++)
		{
			for (int y = 0; y < room.grid.size(); y++)
			{
				int xPos = x * cellSize + cellSize / 2;
				int yPos = y * cellSize + cellSize / 2;

				// only renders cells around the player to make it difficult for the player to make it to the end 
				if (room.grid[x][y]->getX() <= characterOne.getX() / cellSize + fogOfWar && room.grid[x][y]->getX() >= characterOne.getX() / cellSize - fogOfWar)
				{
					if (room.grid[x][y]->getY() <= characterOne.getY() / cellSize + fogOfWar && room.grid[x][y]->getY() >= characterOne.getY() / cellSize - fogOfWar)
					{

						//opens the door when a player goes through
						doorcontroller.Interaction(room, xPos, yPos, characterOne, oxygen);
						doorcontroller.Interaction(room, xPos, yPos, NpcOne, oxygen);

						//Spawns fire randomly in rooms over time
						fire.spawn(room, x, y);
						fire.fireSpread(room, x, y);

						// Runs Oxygen spread function
						oxygen.update(room, x, y);

						// Checks if the cell is a room
						if (room.grid[x][y]->isRoom)
						{
							oxygenTex.alterTransparency(room.grid[x][y]->oxygenLevel);
							roomCell.render(renderer, xPos, yPos, cellSize, cellSize);
							oxygenTex.render(renderer, xPos, yPos, cellSize, cellSize);
						}

						// Renders the top cell orientation
						if (room.grid[x][y]->cellOrientation == 0)
						{
							oxygenTex.alterTransparency(room.grid[x][y]->oxygenLevel / 2);
							topRoomCell.render(renderer, xPos, yPos, cellSize, cellSize);
							oxygenTex.render(renderer, xPos, yPos, cellSize, cellSize);
						}
						if (room.grid[x][y]->cellOrientation == 1)
						{
							oxygenTex.alterTransparency(room.grid[x][y]->oxygenLevel / 2);
							topRightRoomCell.render(renderer, xPos, yPos, cellSize, cellSize);
							oxygenTex.render(renderer, xPos, yPos, cellSize, cellSize);
						}
						if (room.grid[x][y]->cellOrientation == 2)
						{
							oxygenTex.alterTransparency(room.grid[x][y]->oxygenLevel / 2);
							rightRoomCell.render(renderer, xPos, yPos, cellSize, cellSize);
							oxygenTex.render(renderer, xPos, yPos, cellSize, cellSize);
						}
						if (room.grid[x][y]->cellOrientation == 3)
						{
							oxygenTex.alterTransparency(room.grid[x][y]->oxygenLevel / 2);
							bottomRightRoomCell.render(renderer, xPos, yPos, cellSize, cellSize);
							oxygenTex.render(renderer, xPos, yPos, cellSize, cellSize);
						}
						if (room.grid[x][y]->cellOrientation == 4)
						{
							oxygenTex.alterTransparency(room.grid[x][y]->oxygenLevel / 2);
							bottomRoomCell.render(renderer, xPos, yPos, cellSize, cellSize);
							oxygenTex.render(renderer, xPos, yPos, cellSize, cellSize);
						}
						if (room.grid[x][y]->cellOrientation == 5)
						{
							oxygenTex.alterTransparency(room.grid[x][y]->oxygenLevel / 2);
							bottomLeftRoomCell.render(renderer, xPos, yPos, cellSize, cellSize);
							oxygenTex.render(renderer, xPos, yPos, cellSize, cellSize);
						}
						if (room.grid[x][y]->cellOrientation == 6)
						{
							oxygenTex.alterTransparency(room.grid[x][y]->oxygenLevel / 2);
							leftRoomCell.render(renderer, xPos, yPos, cellSize, cellSize);
							oxygenTex.render(renderer, xPos, yPos, cellSize, cellSize);
						}
						if (room.grid[x][y]->cellOrientation == 7)
						{
							oxygenTex.alterTransparency(room.grid[x][y]->oxygenLevel / 2);
							topLeftRoomCell.render(renderer, xPos, yPos, cellSize, cellSize);
							oxygenTex.render(renderer, xPos, yPos, cellSize, cellSize);
						}
						if (room.grid[x][y]->cellOrientation == 8)
						{
							oxygenTex.alterTransparency(room.grid[x][y]->oxygenLevel / 2);
							roomCell.render(renderer, xPos, yPos, cellSize, cellSize);
							oxygenTex.render(renderer, xPos, yPos, cellSize, cellSize);
						}
						// Checks if the cell is a door
						if (room.grid[x][y]->isOpenDoor)
						{
							closedDoorTexture.render(renderer, xPos, yPos, cellSize, cellSize);
						}

						// Renders the fire cells
						if (room.grid[x][y]->isOnFire)
						{
							fireTexture.alterTransparency(150);
							fireTexture.render(renderer, xPos, yPos, cellSize, cellSize);
						}
						// Renders the hullBreach
						if (room.grid[x][y]->isHullBreach)
						{
							hullBreachTexture.alterTransparency(150);
							hullBreachTexture.render(renderer, xPos, yPos, cellSize, cellSize);
						}
						// Renders the oxygen Tanks
						if (room.grid[x][y]->isOxygenTank)
						{
							oxygenTank.alterTransparency(200);
							oxygenTank.render(renderer, xPos, yPos, cellSize, cellSize);
						}
						if (room.grid[x][y]->isHealthPack)
						{
							healthPack.alterTransparency(200);
							healthPack.render(renderer, xPos, yPos, cellSize, cellSize);
						}
						// Renders open doors
						if (room.grid[x][y]->isOpenDoor)
						{
							openDoorTexture.render(renderer, xPos, yPos, cellSize, cellSize);
						}
						// Renders closed doors
						if (room.grid[x][y]->isClosedDoor)
						{
							closedDoorTexture.render(renderer, xPos, yPos, cellSize, cellSize);
						}
						//Checks if the cell has the goal on it.
						if (room.grid[x][y]->isGoal)
						{
							oxygenTex.alterTransparency(room.grid[x][y]->oxygenLevel);
							roomCell.render(renderer, xPos, yPos, cellSize, cellSize);
							oxygenTex.render(renderer, xPos, yPos, cellSize, cellSize);
							goalTexture.render(renderer, xPos, yPos, cellSize, cellSize);
						}
						// Fog of war for the NPC
						if (NpcOne.getX() / cellSize <= characterOne.getX() / cellSize + fogOfWar && NpcOne.getX() / cellSize >= characterOne.getX() / cellSize - fogOfWar)
						{
							if (NpcOne.getY() / cellSize <= characterOne.getY() / cellSize + fogOfWar && NpcOne.getY() / cellSize >= characterOne.getY() / cellSize - fogOfWar)
							{
								//NPC orientation
								if (NpcOne.direction == 0)
								{
									npcDown.render(renderer, NpcOne.getX(), NpcOne.getY(), NpcOne.getSize(), NpcOne.getSize());
								}
								else if (NpcOne.direction == 1)
								{
									npcUp.render(renderer, NpcOne.getX(), NpcOne.getY(), NpcOne.getSize(), NpcOne.getSize());
								}
								else if (NpcOne.direction == 2)
								{
									npcRight.render(renderer, NpcOne.getX(), NpcOne.getY(), NpcOne.getSize(), NpcOne.getSize());
								}
								else if (NpcOne.direction == 3)
								{
									npcLeft.render(renderer, NpcOne.getX(), NpcOne.getY(), NpcOne.getSize(), NpcOne.getSize());
								}
							}
						}
						
					}
				}
			} //End for Y loop
		}//End for X loop

		//Renders the path
		//SDL_SetRenderDrawColor(renderer, 255, 10, 128, 255);
		//drawPath(point, room, startPoint, endPoint);

		// Renders the health and oxygen bar
		healthBar.render(renderer, characterOne.getX(), characterOne.getY() - 40, characterOne.health, 10);
		healthBar.alterTransparency(150);
		healthText.render(renderer, characterOne.getX(), characterOne.getY() - 40, 60, 20);
		oxygenBar.render(renderer, characterOne.getX(), characterOne.getY() - 30, oxygen.getOxygenReserves() / 40, 10);
		oxygenBar.alterTransparency(150);
		oxygenText.render(renderer, characterOne.getX(), characterOne.getY() - 30, 60, 20);

		
		// player orientation
		if (characterOne.direction == 0)
		{
			characterDown.render(renderer, characterOne.getX(), characterOne.getY(), characterOne.getSize(), characterOne.getSize());
		}
		else if (characterOne.direction == 1)
		{
			characterUp.render(renderer, characterOne.getX(), characterOne.getY(), characterOne.getSize(), characterOne.getSize());
		}
		else if (characterOne.direction == 2)
		{
			characterRight.render(renderer, characterOne.getX(), characterOne.getY(), characterOne.getSize(), characterOne.getSize());
		}
		else if (characterOne.direction == 3)
		{
			characterLeft.render(renderer, characterOne.getX(), characterOne.getY(), characterOne.getSize(), characterOne.getSize());
		}


		



		// If the character has died the game over screen is displayed
		if (!characterOne.isAlive)
		{

			//Death animation
			SDL_Surface * image = IMG_Load("Resources\\deathAnim.png");
			SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, image);

			Uint32 ticks = SDL_GetTicks();
			Uint32 sprite = (ticks / 500) % 10;

			SDL_Rect srcrect = { sprite * 10, 0, 10, 100, };
			SDL_Rect dstrect = { characterOne.getX() - (characterOne.getSize() / 2), characterOne.getY() - (characterOne.getSize() / 2), characterOne.getSize(), characterOne.getSize() };

			SDL_RenderCopy(renderer, texture, &srcrect, &dstrect);



			// Fades in a red background
			if (timer < 255)
			{
				timer++;
				gameOver.alterTransparency(timer);
				gameOver.render(renderer, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, WINDOW_WIDTH, WINDOW_HEIGHT);
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
			{
				path.erase(path.begin(), path.end());
				traversepath.pathComplete = false;
				traversepath.pathPointIterator = 0;
				SpaceGame::run();
			}
			
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
			else if (timer >= 255 && timer < 300)
			{
				timer++;
				winText.render(renderer, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, WINDOW_WIDTH, WINDOW_HEIGHT);

			}
			else
			{
				//Remove path from the game
				path.erase(path.begin(), path.end());
				traversepath.pathComplete = false;
				traversepath.pathPointIterator = 0;
				SpaceGame::run();
			}
		}


		SDL_RenderPresent(renderer);
	}// End while running
}

void SpaceGame::drawPath(Point& point, Level& level)
{
	// Start at the start point
	
	// tileSize / 2 is added to all coordinates to put them in the centre of the tile
	int lastX = point.getX() * (level.getCellSize() + level.getCellSize()  / 2);
	int lastY = point.getY() * (level.getCellSize() + level.getCellSize() / 2);

	// Step through the path
	for (const Point& point : path)
	{
		int nextX = point.getX() * level.getCellSize() + level.getCellSize() / 2;
		int nextY = point.getY() * level.getCellSize() + level.getCellSize() / 2;

		SDL_RenderDrawLine(renderer, lastX, lastY, nextX, nextY);
		lastX = nextX;
		lastY = nextY;
		
	}
}