#include <iostream>
#include "Card.h"
#include "Casino.h"
#include "Player.h"

int main() {
	srand(time(NULL));
	Casino casino = Casino();

	Player player = Player();
	for (int i = 0; i < 13; i++) {
		player.getCard(casino);
	}
	player.displayCards();
}