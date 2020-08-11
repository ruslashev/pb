#include "evaluator.hh"
#include "arrays.hh"
#include "macros.hh"
#include <iostream>

static unsigned find_fast(unsigned u)
{
	unsigned a, b, r;
	u += 0xe91aaa35;
	u ^= u >> 16;
	u += u << 8;
	u ^= u >> 4;
	b  = (u >> 8) & 0x1ff;
	a  = (u + (u << 2)) >> 19;
	r  = a ^ hash_adjust[b];
	return r;
}

static value evalute_hand(card c1, card c2, card c3, card c4, card c5)
{
	unsigned q, prime_product;
	value s;

	q = c1.rank_bit | c2.rank_bit | c3.rank_bit | c4.rank_bit | c5.rank_bit;

	/* check for Flushes and Straight Flushes */
	if (c1.suit & c2.suit & c3.suit & c4.suit & c5.suit)
		return flushes[q];

	/* check for Straights and High Cards */
	s = unique5[q];
	if (s)
		return s;

	prime_product = c1.prime * c2.prime * c3.prime * c4.prime * c5.prime;

	return hash_values[find_fast(prime_product)];
}

value evalute_hand(card hand[5])
{
	return evalute_hand(hand[0], hand[1], hand[2], hand[3], hand[4]);
}

