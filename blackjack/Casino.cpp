#include "Casino.h"

Casino::Casino() {
	int newSuit = 0;
	for (int i = 0; i < 52; i++) {
		cards[i] = Card(newSuit, i % 13);
		if ((i + 1) % 13 == 0) {
			newSuit++;
		}
	}
}

void Casino::displayDeck() {
	for (int i = 0; i < 52; i++) {
		std::cout << i + 1 << ". ";
		cards[i].display();
		std::cout << std::endl;
	}
}