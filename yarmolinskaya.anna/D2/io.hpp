#ifndef IO_HPP
#define IO_HPP

#include "sequence.hpp"

namespace yarmolinskaya {

bool readSequence(sequence_t &seq);
void printPairs(const sequence_t &seq, bool reverse);

}

#endif
