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

void Casino::dealCards(Player* _player) {
	if (_player->getNumOfCards() >= 10) return;

	_player->getCard(this);
	_player->getCard(this);
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
	bool _boolValue;
	BeginGame(&playerOne);
	BeginGame(&playerTwo);
	system("pause");
	while (!playerOne.getDidFold() || !playerTwo.getDidFold()) {
		Round(&playerOne);
		system("CLS");
		system("pause");
		Round(&playerTwo);
		system("CLS");
		system("pause");
	}
	std::cout << "\nCzy chcesz zagraæ ponownie? (0 - nie, 1 - tak): ";
	std::cin >> _boolValue;
	if (_boolValue) Play();
	return;
}

void Casino::BeginGame(Player* _player) {
	_player->setName();
	system("CLS");
	_player->printName();

	std::cout << std::endl;
	dealCards(_player);
}

void Casino::Round(Player* _player) {
	bool _boolValue;
	system("CLS");
	_player->printName();
	std::cout << std::endl;
	_player->displayCards();
	std::cout << "Czy chcesz spasowac? (0 - nie, 1 - tak): ";
	if (_player->getDidFold() != true) {
		std::cin >> _boolValue;
		_player->setDidFold(_boolValue);
	}
	if (_player->getDidFold() != true) _player->getCard(this);
	_player->displayCards();
}