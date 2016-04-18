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

	bool isCellARoom(int x, int y); //Will find cell that character is on and that cells state
	bool isCellOnFire(int x, int y);
	int getOxygenLevel(int x, int y);
	
	//Different states
	void moveCharacter(const Uint8* keyboardState);
	void reactToFire();
	void wanderAroundRoom();
	
	std::shared_ptr<CharacterState> state;
	int health = 100;
	bool isAlive = true; //Will be used to decide whether alive or dead sprite should be used
	int oxygenLevel = 100; //Will move to cell and then fetch from cell on update

	std::shared_ptr<Grid> currentRoom; //Will be used to check surronding cell states

private:
	int x = 10, y = 10; //Characters intial start X and Y position
	int size = 100;  //The size of the character sprite when rendered 
	int moveSpeed = 1; //The speed that the character intially moves at
};

