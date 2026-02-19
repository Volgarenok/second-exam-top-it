#include "sequence.hpp"
#include <iostream>

namespace yarmolinskaya {

std::pair< bool, bool > readPair(unsigned int &count, char &ch)
{
  if (!(std::cin >> count)) {
    if (std::cin.eof()) {
      return {true, true};
    }
    return {false, false};
  }
  if (!(std::cin >> ch)) {
    return {false, false};
  }
  return {true, false};
}

void printReversed(const sequence_t &seq)
{
  for (std::size_t i = seq.size; i > 0; --i) {
    std::cout << seq.data[i - 1];
  }
  std::cout << '\n';
}

}
