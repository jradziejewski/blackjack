#pragma once
#include <iostream>
#include "Card.h"
#include "Casino.h"

class Player
{
private:
	Card cards[10] = {};
	int numOfCards = 0;
	int points = 0;

	void calculatePoints();
public:
	void getCard(Casino _casino);
	void displayCards();
};

