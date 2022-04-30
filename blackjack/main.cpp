#include <iostream>
#include "Card.h"
#include "Casino.h"

int main() {
	srand(time(NULL));
	Casino casino = Casino();
	for (int i = 0; i < 52; i++) {
		casino.getCard().display();
		std::cout << std::endl;
	}
	casino.shuffleDeck();
	std::cout << "\n\n\n\n";
	for (int i = 0; i < 52; i++) {
		casino.getCard().display();
		std::cout << std::endl;
	}
}