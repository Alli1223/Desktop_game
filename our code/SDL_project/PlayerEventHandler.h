#pragma once
class PlayerEventHandler
{
public:
	PlayerEventHandler();
	~PlayerEventHandler();

	float getMouseX() { return mouseX; }
	float getMouseY() { return mouseY; }

	float setMouseX(float newX) { return mouseX = newX; }
	float setMouseY(float newY) { return mouseY = newY; }

private:
	
	float mouseX;
	float mouseY;

};

