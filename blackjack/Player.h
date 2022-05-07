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
	bool didFold;

	void calculatePoints();
public:
	Player() : numOfCards(0), points(0), didFold(false) {};
	void getCard(Casino* _casino);
	int getNumOfCards() { return numOfCards; };
	void displayCards();
	int getPoints() { calculatePoints(); return points; };
	bool fold() { didFold = true; };
	bool getDidFold() { return didFold; };
	void setDidFold(bool value) { didFold = value; };
};

