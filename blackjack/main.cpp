#include <iostream>
#include "Card.h"
#include "Casino.h"
#include "Player.h"

int main() {
	srand(time(NULL));
	Casino casino = Casino();
	casino.Play();
}