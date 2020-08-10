#pragma once

#include "card.hh"
#include "macros.hh"
#include <string>

enum value
{
	invalid         = 0,
	straight_flush  = 1,
	four_of_a_kind  = 2,
	full_house      = 3,
	flush           = 4,
	straight        = 5,
	three_of_a_kind = 6,
	two_pair        = 7,
	one_pair        = 8,
	high_card       = 9,
};

static strlit value_str[] = {
	[invalid]         = "",
	[straight_flush]  = "Straight Flush",
	[four_of_a_kind]  = "Four of a Kind",
	[full_house]      = "Full House",
	[flush]           = "Flush",
	[straight]        = "Straight",
	[three_of_a_kind] = "Three of a Kind",
	[two_pair]        = "Two Pair",
	[one_pair]        = "One Pair",
	[high_card]       = "High Card",
};

void init_deck(card deck[52]);
std::string show_hand(card *deck, unsigned size);

