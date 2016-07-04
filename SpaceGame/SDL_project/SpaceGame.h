#pragma once

#include "Texture.h"
#include "Level.h"
#include "Map.h"
#include "Point.h"
#include "SDL2_image-2.0.1\include\SDL_image.h"
//! The main class
/*!
This is the main class where the game is laoded and run. 
*/
class SpaceGame
{
public:
	//! A constructor
	SpaceGame();
	//! A deconstructor
	~SpaceGame();

	const Point& getStartPoint() const { return startPoint; }
	int getStartX() const { return startPoint.getX(); }
	int getStartY() const { return startPoint.getY(); }

	//! Main Run loop
	void run();

	//! Pathfinding function
	void SpaceGame::drawPath(Point& point, Level& level, Point startX, Point startY);

	//! Conains the list of nodes that makes the path
	std::vector<Point> path;

	//! The window width 
	static const int WINDOW_WIDTH = 800;
	//! The window height
	static const int WINDOW_HEIGHT = 800;
	//! Coordinates of the mouse 
	int mouse_X, mouse_Y;

	//! Fog of War distance

private:

	//! start point and end point for pathfinding
	Point startPoint, endPoint;

	//! Pointer to the window that the game will be rendered in
	SDL_Window* window;
	//" Pointer to the renderer
	SDL_Renderer* renderer;

	// Textures for game objects
	//! For cells that are a room
	Texture roomCell;
	//! For the Character
	Texture characterTex;
	//! For door cells
	Texture closedDoorTexture;
	Texture openDoorTexture;
	//! To show the oxygen level in a room
	Texture oxygenTex;
	//! To show oxygen tanks
	Texture oxygenTank;
	//! To show fireExtinguisher
	Texture healthPack;
	//! To show the character health
	Texture healthBar;
	//! Label for character health
	Texture healthText;
	//! To show the oxygen level
	Texture oxygenBar;
	//! Label for oxygen level
	Texture oxygenText;
	//! This will display when the player fails to win	
	Texture gameOver;
	//!will display over the background when the player fails to win
	Texture gameOverText;
	//! Is the texture for the win background
	Texture winTexture;
	//! Is the texture for the win text
	Texture winText;
	//! Is the texture for the goal
	Texture goalTexture;
	//! Is the texture for fire
	Texture fireTexture;
	//! Is the texture for the background
	Texture backgroundTexture;
	//! Is the texture for hull breaches
	Texture hullBreachTexture;
	//! Is the death animation texture
	Texture deathAnim;

	//! Are the textures for the different character orientations
	Texture characterLeft;
	Texture characterRight;
	Texture characterUp;
	Texture characterDown;

	//! Are the textures for the differnt sides of the room cells
	Texture topRoomCell;
	Texture topRightRoomCell;
	Texture rightRoomCell;
	Texture bottomRightRoomCell;
	Texture bottomRoomCell;
	Texture bottomLeftRoomCell;
	Texture leftRoomCell;
	Texture topLeftRoomCell;

	//! Whether the game is running or not
	bool running;

	
};

