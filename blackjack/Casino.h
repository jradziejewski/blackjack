#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>       
#include "Card.h"

class Casino
{
private:
	Card cards[52];
	int takenCards[52];
	void resetCards();
public:
	Casino();
	void displayDeck();
	void shuffleDeck();
	Card getCard();
};

