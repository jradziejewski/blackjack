#pragma once
#include <iostream>
#include "Card.h"

class Casino
{
private:
	Card cards[52];
public:
	Casino();
	void displayDeck();
};

