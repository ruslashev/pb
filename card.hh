#pragma once

#include <cstdint>
#include <string>

/* +--------+--------+--------+--------+
 * |xxxbbbbb|bbbbbbbb|cdhsrrrr|xxpppppp|
 * +--------+--------+--------+--------+
 *
 * p = prime number of rank (deuce = 2, trey = 3, four = 5, five = 7, ... ace = 41)
 * r = rank of card (deuce = 0, trey = 1, four = 2, five = 3, ... ace = 12)
 * cdhs = suit of card (bit turned on based on suit of card)
 * b = bit turned on depending on rank of card
 */
union card
{
	struct
	{
		uint32_t prime    : 6;
		uint32_t unused   : 2;
		uint32_t rank     : 4;
		uint32_t suit     : 4;
		uint32_t rank_bit : 13;
		uint32_t pad      : 3;
	};
	uint32_t data;

	std::string show();
};
static_assert(sizeof(card) == 4, "card must be 32 bits");

enum suit
{
	clubs    = 0b1000,
	diamonds = 0b0100,
	hearts   = 0b0010,
	spades   = 0b0001,
};

enum rank
{
	deuce = 0,
	trey  = 1,
	four  = 2,
	five  = 3,
	six   = 4,
	seven = 5,
	eight = 6,
	nine  = 7,
	ten   = 8,
	jack  = 9,
	queen = 10,
	king  = 11,
	ace   = 12,
};

static const int primes[] = {
	[deuce] = 2,
	[trey]  = 3,
	[four]  = 5,
	[five]  = 7,
	[six]   = 11,
	[seven] = 13,
	[eight] = 17,
	[nine]  = 19,
	[ten]   = 23,
	[jack]  = 29,
	[queen] = 31,
	[king]  = 37,
	[ace]   = 41,
};

void set_card(card *card, uint32_t rank, uint32_t suit);

