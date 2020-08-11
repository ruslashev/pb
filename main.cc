#include "tests.hh"
#include "macros.hh"
#include <iostream>

mb_unused static void do_tests()
{
	tests_card_platform_test();
	std::cout << std::endl;

	tests_show_deck();
	std::cout << std::endl;

	tests_5hand_evaluation();
}

int main()
{
	do_tests();
}

