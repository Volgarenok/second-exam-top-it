#ifndef SEQUENCE_HPP
#define SEQUENCE_HPP
#include <cstddef>

namespace yarmolinskaya {

struct sequence_t {
  char *data;
  std::size_t size;
  std::size_t capacity;
};

sequence_t createSequence();
void destroySequence(sequence_t &seq);
bool appendChar(sequence_t &seq, char ch);

}

#endif
