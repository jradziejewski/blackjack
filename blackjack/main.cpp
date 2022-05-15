#include <iostream>
#include "Card.h"
#include "Casino.h"
#include "Player.h"

/*
W KLASIE KARTA PRZETLUMACZYLEM 
JEDYNIE NAZWY FUNKCJI ABY ZACHOWAC 
SPOJNOSC W NAZEWNICTWIE 
*/

int main() {
	srand(time(NULL));
	Casino casino = Casino();
	casino.Play();
}