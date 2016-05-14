#pragma once
#include"Grid.h"
#include"Cell.h"
class CharacterState; //forward declartion I think

class Character
{//Abstract character class that the other types of character will inherit from
public:
	Character();
	~Character();
		
	//Getter methods
	int getX() { return x; }
	int getY() { return y; }
	int getPreviousX() { return previousX; }
	int getPreviousY() { return previousY; }
	int getSize() { return size; }
	int getSpeed() { return speed; }

	//Setter methods
	int setX(int newX) { return x = newX; }
	int setY(int newY) { return y = newY; }
	int setPreviousX(int newX) { return previousX = newX; }
	int setPreviousY(int newY) { return previousY = newY; }
	int setSpeed(int newSpeed) { return speed = newSpeed; }
	
	//Cell checking functions
	bool isCellARoom(int x, int y);
	bool isCellOnFire(int x, int y);
	int getOxygenLevel(int x, int y);
	// Sets the current X and Y value as the previousX and previousY value
	void setPreviousLocation(int x, int y);
	// Checks if the next move will put the character back to where they were before the last update
	bool checkLocation(int x, int y);

	
	// Moves the character depending on the player's input
	void moveCharacter(const Uint8* keyboardState);
	// Makes the chacacter move away from fire
	void reactToFire();
	// If the user doesn't input a move for a given time the character will wander around
	void wanderAroundRoom();
	
	//Stores the characters current state 
	std::shared_ptr<CharacterState> state;
	//Pointer to the grid being used in SpaceGame, used to check the state of a given cell.
	std::shared_ptr<Grid> currentRoom; 
	std::vector<std::shared_ptr<Cell>> getNeighbourCells();
	std::vector<std::shared_ptr<Cell>> Character::checkNeighbourCells();

	//Character health level, will change to use getters and setters
	int health = 100;
	bool isAlive = true; 
	// Timer is used to count how long the character has been in the idle state
	double timer = 0;
	// The different speed options for use in different states
	int suffocatingSpeed = 1, wanderSpeed = 2, walkSpeed = 3, runSpeed = 3;

private:
	int x = 50, y = 50; //Characters intial start X and Y position
	int previousX = 49, previousY = 49; //stores previous coordinates
	int size = 50;  //The size of the character sprite when rendered 
	int speed = 3; //The speed that the character intially moves at
};

