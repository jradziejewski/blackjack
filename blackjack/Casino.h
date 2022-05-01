#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>       
#include "Card.h"
#include "Player.h"

class Casino
{
private:
	Card cards[52];
	Player playerOne;
	Player playerTwo;
	int takenCards[52];

	void resetCards();
public:
	Casino();
	void displayDeck();
	void shuffleDeck();
	Card getCard();
	void Play();
};

