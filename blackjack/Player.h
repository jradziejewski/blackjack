#pragma once
#include <iostream>
#include "Card.h"

class Casino;

class Player
{
private:
	Card cards[10];
	char name[20];
	int numOfCards;
	int points;
	bool didFold;

	void calculatePoints();
public:
	Player() : numOfCards(0), points(0), didFold(false) {};
	bool isWinner;
	void getCard(Casino* _casino);
	int getNumOfCards() { return numOfCards; };
	void displayCards();
	void deleteCards();
	int getPoints() { return points; };
	bool fold() { didFold = true; };
	void setDidFold(bool value) { didFold = value; };
	bool getDidFold() { return didFold; };
	void setName();
	void printName();
};

