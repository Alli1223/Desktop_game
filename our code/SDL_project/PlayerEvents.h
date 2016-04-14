#pragma once
class PlayerEvents
{
public:
	PlayerEvents();
	~PlayerEvents();

	float getMouseX() { return mouseX; }
	float getMouseY() { return mouseY; }

	float setMouseX(float newX) { return mouseX = newX; }
	float setMouseY(float newY) { return mouseY = newY; }

private:
	
	float mouseX;
	float mouseY;

};

