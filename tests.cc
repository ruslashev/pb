#include "tests.hh"
#include "card.hh"
#include <cassert>
#include <iostream>

void tests_card_platform_test()
{
	card Kd = { .data = 0b000'0100000000000'0100'1011'00'100101 };
	card Fs = { .data = 0b000'0000000001000'0001'0011'00'000111 };

	assert(Kd.rank_bit == 1 << 11);
	assert(Kd.suit     == 0b0100);
	assert(Kd.rank     == 11);
	assert(Kd.prime    == 37);

	assert(Fs.rank_bit == 1 << 3);
	assert(Fs.suit     == 0b0001);
	assert(Fs.rank     == 3);
	assert(Fs.prime    == 7);

	std::cout << "card platform test: ok" << std::endl;
}

