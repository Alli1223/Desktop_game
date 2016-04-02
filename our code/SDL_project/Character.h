#pragma once
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

	//Update function to be called on every frame update
	void update(); //Maybe not needed
	
	//Different states
	void playerControlled();
	void reactToFire();
	void reactToOxygen();
	void wanderAroundRoom();
	
	std::shared_ptr<CharacterState> state;
	int health = 100;
	bool isAlive = true; //Will be used to decide whether alive or dead sprite should be used

private:
	int x = 10, y = 10; //Characters intial start X and Y position
	int size = 100;  //The size of the character sprite when rendered 
	int moveSpeed = 2; //The speed that the character intially moves at
};

