#pragma once
class Character
{
public:
	Character();
	~Character();

	//Getter methods
	int getX() { return x; }
	int getY() { return y; }
	int getSize() { return size; }

	//Setter methods
	int setX(int newX) { return x = newX; }
	int setY(int newY) { return y = newY; }
	
	//Update function to be called on every frame update
	//Update now takes a direction then updates that charcter's x and y position accordingly
	void update(std::string direction);



private:
	int x = 10, y = 10;
	int size = 100;  //The size of the character sprite when rendered 
};

