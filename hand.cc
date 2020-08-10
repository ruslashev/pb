#include "hand.hh"
#include <iostream>

void init_deck(card deck[52])
{
	for (unsigned i = 0, suit = clubs; suit != 0; suit >>= 1)
		for (unsigned rank = deuce; rank <= ace; ++rank)
			set_card(&deck[i++], rank, suit);
}

