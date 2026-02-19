#include "sequence.hpp"
#include <iostream>

int main()
{
  yarmolinskaya::sequence_t seq = yarmolinskaya::createSequence();
  bool memError = false;

  while (true) {
    unsigned int count = 0;
    char ch = '\0';
    const auto result = yarmolinskaya::readPair(count, ch);
    const bool eof = result.second;
    const bool ok = result.first;

    if (eof) {
      break;
    }
    if (!ok) {
      std::cerr << "Error: failed to read a pair\n";
      yarmolinskaya::destroySequence(seq);
      return 1;
    }
    if (!yarmolinskaya::appendChars(seq, ch, count)) {
      std::cerr << "Error: memory allocation failed\n";
      memError = true;
      break;
    }
  }
}
