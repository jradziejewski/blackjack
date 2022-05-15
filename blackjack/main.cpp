#include <iostream>
#include "Card.h"
#include "Casino.h"
#include "Player.h"
const char suits[] = { 3, 4, 5, 6 };
/*
W KLASIE KARTA PRZETLUMACZYLEM
JEDYNIE NAZWY FUNKCJI ABY ZACHOWAC
SPOJNOSC W NAZEWNICTWIE
*/

/*
W KLASIE KARTA PRZETLUMACZYLEM 
JEDYNIE NAZWY FUNKCJI ABY ZACHOWAC 
SPOJNOSC W NAZEWNICTWIE 
*/

int main() {
	srand(time(NULL));
	//std::cout << suits[0] << std::endl << suits[1] << std::endl << suits[2] << std::endl << suits[3];
	Casino casino = Casino();
	casino.Play();
}