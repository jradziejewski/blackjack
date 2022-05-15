#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>  
#include <iomanip>
#include <map>
#include <algorithm>
#include <string>
#include <fstream>
#include "Card.h"
#include "Player.h"

class Casino
{
private:
	Card cards[52];
	Player playerOne;
	Player playerTwo;
	Player playerThree;
	int takenCards[52];
	int numOfPlayers;

	void resetCards();
public:
	Casino();
	void shuffleDeck();
	void displayDeck();
	void dealCards(Player* player);
	Card getCard();
	void Play();
	void BeginGame(Player* _player);
	void Round(Player* _player);
	int pickWinner();
	void exportResults();
};

