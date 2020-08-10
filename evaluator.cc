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
	uint32_t q;
	value s;

	uint32_t v1 = c1.data,
	         v2 = c2.data,
	         v3 = c3.data,
	         v4 = c4.data,
	         v5 = c5.data;

	q = (v1 | v2 | v3 | v4 | v5) >> 16;

	/* check for Flushes and StraightFlushes */
	if (v1 & v2 & v3 & v4 & v5 & 0xF000)
		return flushes[q];

	/* check for Straights and HighCard hands */
	s = unique5[q];
	if (s)
		return s;

	/* let's do it the hard way */
	q = (v1 & 0xFF) * (v2 & 0xFF) * (v3 & 0xFF) * (v4 & 0xFF) * (v5 & 0xFF);
	q = findit(q);

	return values[q];
}

value evalute_hand(card hand[5])
{
	return evalute_hand(hand[0], hand[1], hand[2], hand[3], hand[4]);
}

