#include "tests.hh"
#include "card.hh"
#include "hand.hh"
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

void tests_show_deck()
{
	card deck[52];

	init_deck(deck);

	for (int i = 0; i < 52; i += 13)
		std::cout << show_hand(deck + i, 13) << std::endl;
}

void tests_hand_evaluation()
{
	card deck[52], hand[5];
	int freq[10];

	init_deck(deck);

	for (int i = 0; i < 10; i++)
		freq[i] = 0;

	/* loop over every possible five-card hand */
	for (int a = 0; a < 48; ++a) {
		hand[0] = deck[a];
		for (int b = a + 1; b < 49; ++b) {
			hand[1] = deck[b];
			for (int c = b + 1; c < 50; ++c) {
				hand[2] = deck[c];
				for (int d = c + 1; d < 51; ++d) {
					hand[3] = deck[d];
					for (int e = d + 1; e < 52; ++e) {
						hand[4] = deck[e];

						value v = evalute_hand(hand);
						hand_rank r = get_hand_rank(v);
						++freq[r];
					}
				}
			}
		}
	}

	uint32_t sum = 0;
	for (int i = royal_flush; i <= high_card; ++i) {
		printf("%15s: %8d\n", hand_rank_str[i], freq[i]);
		sum += freq[i];
	}
	printf("%15s: %8d\n", "Total", sum);
}

