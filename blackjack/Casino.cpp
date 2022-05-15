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

	_player->takeCard(this);
	_player->takeCard(this);
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
	system("CLS");
	std::cout << "Please enter number of players: ";
	char temp;
	std::cin >> temp;
	switch (temp) {
	case '1':
		numOfPlayers = 1;
		break;
	case '2':
		numOfPlayers = 2;
		break;
	case '3':
		numOfPlayers = 3;
		break;
	default: Play();
	}
	shuffleDeck();
	bool _boolValue;
	BeginGame(&playerOne);
	if (numOfPlayers > 1)
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
	else if (numOfPlayers > 1) {
		while (!playerOne.getDidFold() || !playerTwo.getDidFold()) {
			system("CLS");
			Round(&playerOne);
			system("CLS");
			Round(&playerTwo);
		}
	}
	else {
		while (!playerOne.getDidFold()) {
			system("CLS");
			Round(&playerOne);
		}
	}
	system("CLS");
	int result = pickWinner();
	switch (result) {
	case 1:
		std::cout << "The winner is " << playerOne.getName();
		break;
	case 2:
		std::cout << "The winner is " << playerTwo.getName();
		break;
	case 3:
		std::cout << "The winner is " << playerThree.getName();
		break;
	default:
		std::cout << "No one won.";
		break;
	}
	exportResults();
	std::cout << "\nDo you want to play again? (1 - yes, anything else - no): ";
	std::cin >> temp;
	if (temp == '1') {
		Play();
	}
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
	char temp;
	system("CLS");
	_player->printName();
	std::cout << std::endl;
	_player->displayCards();
	if (_player->getPoints() >= 21) _player->setDidFold(true);
	if (_player->getDidFold() != true) {
		std::cout << "Do you want to fold? (1 - yes, anything else - no): ";
		std::cin >> temp;
		switch (temp) {
		case '1':
			_boolValue = true;
			break;
		default:
			_boolValue = false;
			break;
		}
		_player->setDidFold(_boolValue);
	}
	if (_player->getDidFold() != true) _player->takeCard(this);
	_player->displayCards();
}

int Casino::pickWinner() {
	if (playerOne.getPoints() > 21) {
		playerOne.isWinner = false;
	}
	if (numOfPlayers == 1 && playerOne.isWinner != false) {
		return 1;
	}
	if (playerTwo.getPoints() > 21) {
		playerTwo.isWinner = false;
	}
	if (playerThree.getPoints() > 21) {
		playerThree.isWinner = false;
	}

	if (numOfPlayers > 1) {
		if (playerOne.getPoints() == playerTwo.getPoints()) {
			std::cout << "Draw between player One and Two.";
			return 0;
		}
		if (numOfPlayers > 2)
			if (playerOne.getPoints() == playerThree.getPoints()) {
				std::cout << "Draw between player One and Three.";
				return 0;
			}
			else if (playerTwo.getPoints() == playerThree.getPoints()) {
				std::cout << "Draw between player Two and Three.";
				return 0;
			}
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
	return winner->first;
}

std::string convertSuit(char _suit) {
	std::string suit;
	if (_suit == 3) {
		suit = "[<3]";
		return suit;
	}
	else if (_suit == 4) {
		suit = "[<>]";
		return suit;
	}
	else if (_suit == 5) {
		suit = "[=3]";
		return suit;
	}
	else if (_suit == 6) {
		return "[B>]";
	}
}

void Casino::exportResults() {
	std::ofstream results;
	results.open("results.txt");
	results.setf(std::ios::left);
	results.setf(std::ios::uppercase);
	results << std::setw(20) << playerOne.getName();
	results << std::setw(10) << "Points: " << playerOne.getPoints();
	results << "     Cards: ";
	for (int i = 0; i < playerOne.getNumOfCards(); i++) {
		Card card = playerOne.getCard(i);
		results << card.getFace() << convertSuit(card.getSuit()) << ", ";
	}
	results << std::endl;
	if (numOfPlayers > 1) {
		results << std::setw(20) << playerTwo.getName();
		results << std::setw(10) << "Points: " << playerTwo.getPoints();
		results << "     Cards: ";
		for (int i = 0; i < playerTwo.getNumOfCards(); i++) {
			Card card = playerTwo.getCard(i);
			results << card.getFace() << convertSuit(card.getSuit()) << ", ";
		}
		results << std::endl;
	}
	if (numOfPlayers > 2) {
		results << std::setw(20) << playerThree.getName();
		results << std::setw(10) << "Points: " << playerThree.getPoints();
		results << "     Cards: ";
		for (int i = 0; i < playerThree.getNumOfCards(); i++) {
			Card card = playerThree.getCard(i);
			results << card.getFace() << convertSuit(card.getSuit()) << ", ";
		}
		results << std::endl;
	}
	results.close();
}