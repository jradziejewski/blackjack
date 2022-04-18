#include "Casino.h"

Casino::Casino() {
	for (int i = 0; i < 52; i++) {
		int newSuit = 0;
		cards[i].setSuit(newSuit);
		cards[i].setValue(i % 13);
		if ((i + 1) % 13 == 0)
			newSuit++;
	}
}