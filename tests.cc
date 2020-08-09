#include "tests.hh"
#include "card.hh"
#include <cassert>
#include <iostream>

void tests_card_platform_test()
{
	card Kd = { .data = 0b000'0100000000000'0100'1011'00'100101 };
	card Fs = { .data = 0b000'0000000001000'0001'0011'00'000111 };

	assert(Kd.rank_bit == 1 << king);
	assert(Kd.suit     == diamonds);
	assert(Kd.rank     == king);
	assert(Kd.prime    == primes[king]);

	assert(Fs.rank_bit == 1 << five);
	assert(Fs.suit     == spades);
	assert(Fs.rank     == five);
	assert(Fs.prime    == primes[five]);

	std::cout << "card platform test: ok" << std::endl;
}

