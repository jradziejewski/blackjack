#include "Player.h"
#include "Casino.h"

void Player::calculatePoints() {
	for (int i = 0; i < numOfCards; i++) {
		points += cards[i].getValue();
	}
}

void Player::getCard(Casino* _casino) {
	if (numOfCards < 10) {
		cards[numOfCards] = _casino->getCard();
		numOfCards++;
	}
}

void Player::displayCards() {
	for (int i = 0; i < numOfCards; i++) {
		cards[i].display();
		if (i < 9) std::cout << ", ";
	}
}