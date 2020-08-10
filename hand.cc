#include "hand.hh"
#include <iostream>

void init_deck(card deck[52])
{
	for (unsigned i = 0, suit = clubs; suit != 0; suit >>= 1)
		for (unsigned rank = deuce; rank <= ace; ++rank)
			set_card(&deck[i++], rank, suit);
}

std::string show_hand(card *deck, unsigned size)
{
	std::string out = "";

	for (unsigned i = 0; i < size - 1; ++i)
		out += deck[i].show() + " ";

	return out + deck[size - 1].show();
}

hand_rank get_hand_rank(value val)
{
	if (val > 6185) return high_card;        // 1277 high card
	if (val > 3325) return one_pair;         // 2860 one pair
	if (val > 2467) return two_pair;         //  858 two pair
	if (val > 1609) return three_of_a_kind;  //  858 three-kind
	if (val > 1599) return straight;         //   10 straights
	if (val > 322)  return flush;            // 1277 flushes
	if (val > 166)  return full_house;       //  156 full house
	if (val > 10)   return four_of_a_kind;   //  156 four-kind
	if (val > 1)    return straight_flush;   //    9 straight-flushes
	return royal_flush;                      //    1 royal flush
}

