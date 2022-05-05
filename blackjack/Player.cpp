#include "Player.h"

void Player::calculatePoints() {
	for (int i = 0; i < numOfCards; i++) {
		points += cards[i].getValue();
	}
}

void Player::getCard(Card* _card) {
	if (numOfCards < 10) {
		cards[numOfCards] = *_card;
		numOfCards++;
	}
}

void Player::displayCards() {
	for (int i = 0; i < numOfCards; i++) {
		cards[i].display();
		if (i < 9) std::cout << ", ";
	}
}