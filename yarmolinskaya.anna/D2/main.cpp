#include "io.hpp"
#include <iostream>

namespace yarmolinskaya {

static void printPair(char ch, std::size_t count)
{
  std::cout << count << ' ' << ch << '\n';
}

bool readSequence(sequence_t &seq)
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

void printPairs(const sequence_t &seq, bool reverse)
{
  if (seq.size == 0) {
    std::cout << '\n';
    return;
  }

  if (!reverse) {
    std::size_t i = 0;
    while (i < seq.size) {
      const char current = seq.data[i];
      std::size_t count = 0;
      while (i < seq.size && seq.data[i] == current) {
        ++count;
        ++i;
      }
      printPair(current, count);
    }
  } else {
    std::size_t i = seq.size;
    while (i > 0) {
      const char current = seq.data[i - 1];
      std::size_t count = 0;
      while (i > 0 && seq.data[i - 1] == current) {
        ++count;
        --i;
      }
      printPair(current, count);
    }
  }
}

}
