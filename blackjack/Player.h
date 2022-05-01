#pragma once
#include <iostream>
#include "Card.h"

class Player
{
private:
	Card cards[10];
	int numOfCards;
	int points;

	void calculatePoints();
public:
	Player() : numOfCards(0), points(0) {};
	void getCard(Card* _casino);
	int getNumOfCards() { return numOfCards; };
	void displayCards();
};

