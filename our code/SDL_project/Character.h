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
	
	//Cell checking functions
	bool isCellARoom(int x, int y);
	bool isCellADoor(int x, int y);
	bool canWanderInRoom(int x, int y);
	int getOxygenLevel(int x, int y);

	int getRandomNumber(int smallestValue, int largestValue);
	int direction = 1;
	
	// Moves the character depending on the player's input
	void moveCharacter(const Uint8* keyboardState);
	// If the user doesn't input a move for a given time the character will wander around
	void wanderAroundRoom();
	
	//Stores the characters current state 
	std::shared_ptr<CharacterState> state;
	//Pointer to the grid being used in SpaceGame, used to check the state of a given cell.
	std::shared_ptr<Grid> currentRoom; 
	std::vector<std::shared_ptr<Cell>> getNeighbourCells();
	std::vector<std::shared_ptr<Cell>> Character::checkNeighbourCells();

	//Character health level, will change to use getters and setters
	double health = 100;
	bool isAlive = true; 
	// Timer is used to count how long the character has been in the idle state
	double timer = 0;
	// The different speed options for use in different states
	int suffocatingSpeed = 1, wanderSpeed = 2, walkSpeed = 3, runSpeed = 3;

private:
	// Characters X and Y position
	int x = 50, y = 50; 
	int size = 50;  //The size of the character sprite when rendered 
	int speed = 3; //The speed that the character intially moves at
};

