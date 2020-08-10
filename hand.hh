#pragma once

#include "card.hh"
#include <string>

void init_deck(card deck[52]);
std::string show_hand(card *deck, unsigned size);

