#include "sequence.hpp"
#include <iostream>

int main()
{
  yarmolinskaya::sequence_t seq = yarmolinskaya::createSequence();

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
      yarmolinskaya::printReversed(seq);
      yarmolinskaya::destroySequence(seq);
      std::cerr << "Error: failed to read a pair\n";
      return 1;
    }
    if (!yarmolinskaya::appendChars(seq, ch, count)) {
      yarmolinskaya::printReversed(seq);
      yarmolinskaya::destroySequence(seq);
      std::cerr << "Error: memory allocation failed\n";
      return 2;
    }
  }

  yarmolinskaya::printReversed(seq);
  yarmolinskaya::destroySequence(seq);
  return 0;
}
