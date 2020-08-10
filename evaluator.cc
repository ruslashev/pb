#include "evaluator.hh"
#include "arrays.hh"
#include "macros.hh"
#include <iostream>

/* perform a binary search on a pre-sorted array */
int findit(uint32_t key)
{
	int low = 0, high = 4887, mid;

	while (low <= high) {
		mid = (high + low) >> 1;      // divide by two
		if (key < products[mid])
			high = mid - 1;
		else if (key > products[mid])
			low = mid + 1;
		else
			return mid;
	}

	die("findit: no match found for key = " << key);
}

static value evalute_hand(card c1, card c2, card c3, card c4, card c5)
{
	unsigned q, prime_product;
	value s;

	q = c1.rank_bit | c2.rank_bit | c3.rank_bit | c4.rank_bit | c5.rank_bit;

	/* check for Flushes and StraightFlushes */
	if (c1.suit & c2.suit & c3.suit & c4.suit & c5.suit)
		return flushes[q];

	/* check for Straights and HighCard hands */
	s = unique5[q];
	if (s)
		return s;

	/* let's do it the hard way */
	prime_product = c1.prime * c2.prime * c3.prime * c4.prime * c5.prime;

	return values[findit(prime_product)];
}

value evalute_hand(card hand[5])
{
	return evalute_hand(hand[0], hand[1], hand[2], hand[3], hand[4]);
}

