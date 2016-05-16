#pragma once
#include"Grid.h"
#include"Cell.h"
#include <cstdlib>
#include <ctime>
class CharacterState; //forward declartion I think

class Character
{//Abstract character class that the other types of character will inherit from
public:
	Character();
	~Character();
		
	//Getter methods
	int getX() { return x; }
	int getY() { return y; }
	int getSize() { return size; }
	int getSpeed() { return speed; }

	//Setter methods
	int setX(int newX) { return x = newX; }
	int setY(int newY) { return y = newY; }
	int setSpeed(int newSpeed) { return speed = newSpeed; }
	
	//Pointer to the grid being used in SpaceGame
	std::shared_ptr<Grid> currentRoom;

	//Cell checking functions
	bool isCellARoom(int x, int y);
	bool isCellADoor(int x, int y);
	//Checks to see if a cell is a room cell but not a door cell
	bool canWanderInRoom(int x, int y);
	int getOxygenLevel(int x, int y);

	// Chooses a random number between a given range
	int getRandomNumber(int smallestValue, int largestValue);
	// Moves the character depending on the player's input
	void moveCharacter(const Uint8* keyboardState);
	// If the user doesn't input a move for a given time the character will wander around
	void wanderAroundRoom();
	
	//Stores the characters current state 
	std::shared_ptr<CharacterState> state;
	
	double health = 100;
	// Whether character is alive or not
	bool isAlive = true; 
	// The direction that the character will move in when in the wandering state
	int direction = 1;
	// Timer is used to count how long the character has been in the idle state
	double timer = 0;
	// The different speed options for use in different states
	int suffocatingSpeed = 1, wanderSpeed = 2, walkSpeed = 3, runSpeed = 3;

private:
	// Characters X and Y position
	int x = 50, y = 50;
	// The size of the character sprite when rendered 
	int size = 50;
	// The speed at which the character is moved
	int speed = 3; 
};

