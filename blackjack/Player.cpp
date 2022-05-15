#include "Player.h"
#include "Casino.h"

void Player::getCard(Casino* _casino) {
	if (numOfCards < 10) {
		cards[numOfCards] = _casino->getCard();
		points += cards[numOfCards].getValue();
		numOfCards++;
	}
}

void Player::deleteCards() {
	for (int i = 0; i < getNumOfCards(); i++) {
		cards[i] = 0;
	}
	numOfCards = 0;
	points = 0;
}

void Player::displayCards() {
	for (int i = 0; i < numOfCards; i++) {
		cards[i].display();
		if (i < 9) std::cout << ", ";
	}
	std::cout << "\nPoints: " << getPoints() << std::endl;
}

void Player::setName() {
	std::cout << "Please enter your nickname: ";
	std::cin >> name;
}

void Player::printName() {
	int i = 0;
	while (name[i]) {
		std::cout << name[i];
		i++;
	}
}