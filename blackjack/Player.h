#pragma once
#include <iostream>
#include "Card.h"

class Casino;

class Player
{
private:
	Card cards[10];
	int numOfCards;
	int points;
	bool didPass;

	void calculatePoints();
public:
	Player() : numOfCards(0), points(0), didPass(false) {};
	void getCard(Card* _casino);
	int getNumOfCards() { return numOfCards; };
	void displayCards();
	int getPoints() { calculatePoints(); return points; };
};

