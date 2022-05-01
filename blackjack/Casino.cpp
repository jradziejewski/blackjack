#include "Casino.h"

void Casino::resetCards() {
	for (int i = 0; i < 52; i++) {
		takenCards[i] = 0;
	}
}

Casino::Casino() {
	int newSuit = 0;
	for (int i = 0; i < 52; i++) {
		cards[i] = Card(newSuit, i % 13);
		if ((i + 1) % 13 == 0) {
			newSuit++;
		}
	}
	resetCards();
}

void Casino::shuffleDeck() {
	resetCards();
	for (int i = 0; i < 100; i++) {
		int a = rand() % 52;
		int b = rand() % 52;
		Card temp;
		temp = cards[a];
		cards[a] = cards[b];
		cards[b] = temp;
	}
}

void Casino::displayDeck() {
	for (int i = 0; i < 52; i++) {
		std::cout << i + 1 << ". ";
		cards[i].display();
		std::cout << std::endl;
	}
}

Card Casino::getCard() {
	int nrOfCard;
	do {
		nrOfCard = rand() % 52;
	} while (takenCards[nrOfCard] == 1);
	takenCards[nrOfCard] = 1;

	return cards[nrOfCard];
}

void Casino::Play() {
	std::cout << "Player 1: \n";
	Card temp;
	if (playerOne.getNumOfCards() < 10) {
		temp = getCard();
		playerOne.getCard(&temp);
	}
	if (playerOne.getNumOfCards() < 10) {
		temp = getCard();
		playerOne.getCard(&temp);
	}
	playerOne.displayCards();
	std::cout << "\nPlayer 2: \n";
	if (playerTwo.getNumOfCards() < 10) {
		temp = getCard();
		playerTwo.getCard(&temp);
	}
	if (playerTwo.getNumOfCards() < 10) {
		temp = getCard();
		playerTwo.getCard(&temp);
	}
	playerTwo.displayCards();
}