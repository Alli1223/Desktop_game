#pragma once

#include "GameObject.h"

class Coin : public GameObject
{
public:
	Coin(CoinGame* game);
	~Coin();

	virtual void update();
};

