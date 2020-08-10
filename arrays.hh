#pragma once

#include <cstdint>

/* this is a table lookup for all "flush" hands (e.g.  both
 * flushes and straight-flushes.  entries containing a zero
 * mean that combination is not possible with a five-card
 * flush hand.
 */
extern uint16_t flushes[];

/* this is a table lookup for all non-flush hands consisting
 * of five unique ranks (i.e.  either Straights or High Card
 * hands).  it's similar to the above "flushes" array.
 */
extern uint16_t unique5[];

extern uint32_t products[];

extern uint16_t values[];

