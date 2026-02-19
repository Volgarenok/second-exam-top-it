#include "io.hpp"
#include <iostream>

namespace yarmolinskaya {

bool yarmolinskaya::readSequence(sequence_t &seq)
{
  char ch = '\0';
  while (std::cin.get(ch)) {
    if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r') {
      continue;
    }
    if (!appendChar(seq, ch)) {
      return false;
    }
  }
  return true;
}

static void printPair(char ch, std::size_t count)
{
  std::cout << count << ' ' << ch << '\n';
}
}
