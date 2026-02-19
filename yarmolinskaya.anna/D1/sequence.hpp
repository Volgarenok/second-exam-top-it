#ifndef SEQUENCE_HPP
#define SEQUENCE_HPP
#include <cstddef>
#include <utility>

namespace yarmolinskaya {

struct sequence_t {
  char *data;
  std::size_t size;
  std::size_t capacity;
};

sequence_t createSequence();
void destroySequence(sequence_t &seq);
bool appendChars(sequence_t &seq, char ch, unsigned int count);
void printReversed(const sequence_t &seq);

std::pair< bool, bool > readPair(unsigned int &count, char &ch);

}

#endif
