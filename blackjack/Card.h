#pragma once
#include <iostream>

class Card {
private:
	char suit;
	char face;
	int value;
public:
	Card(int _suit = 0, int _value = 0);
	void setSuit(int _kolor);
	void setValue(int _wartosc);
	char getSuit() const { return suit; }
	char getFace() const { return face; }
	int getValue() const { return value; }
	void display() const { std::cout << face << suit; }
};