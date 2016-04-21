#pragma once
#include"Grid.h"
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
	int getSpeed() { return moveSpeed; }

	//Setter methods
	int setX(int newX) { return x = newX; }
	int setY(int newY) { return y = newY; }
	int setSpeed(int newSpeed) { return moveSpeed = newSpeed; }
	
	//Cell checking functions
	bool isCellARoom(int x, int y);
	bool isCellOnFire(int x, int y);
	int getOxygenLevel(int x, int y);
	
	//Different states
	void moveCharacter(const Uint8* keyboardState);
	void reactToFire();
	void wanderAroundRoom();
	
	//Stores the characters current state 
	std::shared_ptr<CharacterState> state;
	//Pointer to the grid being used in SpaceGame, used to check the state of a given cell.
	std::shared_ptr<Grid> currentRoom; 

	int health = 100; //Character health level, will change to use getters and setters
	bool isAlive = true; //Will be used to decide whether alive or dead sprite should be used
	double timer = 0;
	//int previousX, previousY;

private:
	int x = 50, y = 50; //Characters intial start X and Y position
	int size = 100;  //The size of the character sprite when rendered 
	int moveSpeed = 3; //The speed that the character intially moves at
	// TODO: Add other speeds normal, running & oxygen deprived
};

