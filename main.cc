#include "tests.hh"
#include <iostream>

int main()
{
	tests_card_platform_test();
	std::cout << std::endl;

	tests_show_deck();
	std::cout << std::endl;

	tests_hand_evaluation();
}

