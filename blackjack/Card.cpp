#include "Card.h"

const char suits[] = { 3, 4, 5, 6 };
const char faces[] = { '2', '3', '4', '5', '6', '7', '8', '9', 'D', 'J', 'Q', 'K', 'A' };
const int values[] = { 2,   3,   4,   5,   6,   7 ,  8,   9,  10,   2,   3,   4,  11 };

Card::Card(int _kolor, int _value) {
	setSuit(_kolor);
	setValue(_value);
}

void Card::setSuit(int _suit) {
	if (_suit < 4) {
		suit = suits[_suit];
	}
}

void Card::setValue(int _value) {
	if (_value < 14) {
		face = faces[_value];
		value = values[_value];
	}
}