#pragma once

#include <cstdint>

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
		uint32_t pad      : 3;
		uint32_t rank_bit : 13;
		uint32_t suit     : 4;
		uint32_t rank_val : 4;
		uint32_t unused   : 2;
		uint32_t prime    : 6;
	};
	uint32_t raw;
};
static_assert(sizeof(card) == 4, "card must be 32 bits");

