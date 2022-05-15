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
	std::cout << "Please enter number of players: ";
	std::cin >> numOfPlayers;
	shuffleDeck();
	bool _boolValue;
	BeginGame(&playerOne);
	BeginGame(&playerTwo);
	if (numOfPlayers > 2)
		BeginGame(&playerThree);
	system("pause");
	if (numOfPlayers > 2) {
		while (!playerOne.getDidFold() || !playerTwo.getDidFold() || !playerThree.getDidFold()) {
			system("CLS");
			Round(&playerOne);
			system("CLS");
			Round(&playerTwo);
			system("CLS");
			Round(&playerThree);
		}
	}
	else {
		while (!playerOne.getDidFold() || !playerTwo.getDidFold()) {
			system("CLS");
			Round(&playerOne);
			system("CLS");
			Round(&playerTwo);
		}
	}
	system("CLS");
	playerOne.displayCards();
	playerTwo.displayCards();
	playerThree.displayCards();
	pickWinner();

	std::cout << "\nDo you want to play again? (0 - no, 1 - yes): ";
	std::cin >> _boolValue;
	if (_boolValue) Play();
	return;
}

void Casino::BeginGame(Player* _player) {
	_player->setName();
	system("CLS");
	_player->printName();
	_player->deleteCards();
	_player->setDidFold(false);
	std::cout << std::endl;
	dealCards(_player);
}

void Casino::Round(Player* _player) {
	bool _boolValue;
	system("CLS");
	_player->printName();
	std::cout << std::endl;
	_player->displayCards();
	if (_player->getPoints() >= 21) _player->setDidFold(true);
	if (_player->getDidFold() != true) {
		std::cout << "Do you want to fold? (0 - no, 1 - yes): ";
		std::cin >> _boolValue;
		_player->setDidFold(_boolValue);
	}
	if (_player->getDidFold() != true) _player->getCard(this);
	_player->displayCards();
}

void Casino::pickWinner() {
	if (playerOne.getPoints() > 21) {
		playerOne.isWinner = false;
	}
	if (playerTwo.getPoints() > 21) {
		playerTwo.isWinner = false;
	}
	if (playerThree.getPoints() > 21) {
		playerThree.isWinner = false;
	}
	if (playerOne.getPoints() == playerTwo.getPoints()) {
		std::cout << "Draw between player One and Two.";
		return;
	}
	else if (playerOne.getPoints() == playerThree.getPoints()) {
		std::cout << "Draw between player One and Three.";
		return;
	}
	else if (playerTwo.getPoints() == playerThree.getPoints()) {
		std::cout << "Draw between player Two and Three.";
		return;
	}
	std::map<int, int> results;
	if (playerOne.isWinner != false) {
		results[1] = playerOne.getPoints();
	}
	if (playerTwo.isWinner != false) {
		results[2] = playerTwo.getPoints();
	}
	if (playerThree.isWinner != false) {
		results[3] = playerThree.getPoints();
	}

	auto winner = std::max_element(results.begin(), results.end(), [](const auto& x, const auto& y) {
		return x.second < y.second;
		});
	std::cout << "Winner: Player " << winner->first;
}