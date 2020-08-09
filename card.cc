#include "card.hh"
#include "macros.hh"

namespace colors
{
static strlit reset    = "\x1b[0m";
static strlit white_bg = "\x1b[47m";
static strlit black    = "\x1b[38;2;65;65;65m";
static strlit red      = "\x1b[31m";
static strlit green    = "\x1b[32m";
static strlit blue     = "\x1b[34m";
};

static std::string suit_color_standard(uint32_t suit)
{
	switch (suit) {
	case clubs:
	case spades:   return colors::black;
	case hearts:
	case diamonds: return colors::red;
	default:       die("suit_color_standard: bad suit");
	}
}

static std::string suit_color_4colors(uint32_t suit)
{
	switch (suit) {
	case clubs:    return colors::green;
	case hearts:   return colors::red;
	case diamonds: return colors::blue;
	case spades:   return colors::black;
	default:       die("suit_color_4colors: bad suit");
	}
}

static std::string suit_to_string(uint32_t suit)
{
	switch (suit) {
	case clubs:    return "♣";
	case hearts:   return "♥";
	case diamonds: return "♦";
	case spades:   return "♠";
	default:       die("suit_to_string: bad suit");
	}
}

static std::string rank_to_string(uint32_t r)
{
	switch (r) {
	case ace:   return "A";
	case king:  return "K";
	case queen: return "Q";
	case jack:  return "J";
	case ten:   return "T";
	case nine:  return "9";
	case eight: return "8";
	case seven: return "7";
	case six:   return "6";
	case five:  return "5";
	case four:  return "4";
	case trey:  return "3";
	case deuce: return "2";
	default:    die("rank_to_string: bad rank");
	}
}

std::string card::show()
{
	bool white_bg = false;
	bool standard_colors = true;

	return (white_bg ? colors::white_bg : "")
		+ (standard_colors ? suit_color_standard(suit) : suit_color_4colors(suit))
		+ rank_to_string(rank) + suit_to_string(suit) + colors::reset;
}

