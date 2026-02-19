#include "array_processing.hpp"

#include <iostream>
#include <utility>

int main()
{
  int error_code = 0;
  std::pair<char *, std::size_t> result = smirnova::buildSequence(error_code);

  if (error_code == 1) {
    std::cerr << "Error: failed to read a pair element\n";
    smirnova::printReverse(result.first, result.second);
    delete[] result.first;
    return 1;
  }

  if (error_code == 2) {
    std::cerr << "Error: failed to allocate memory\n";
    smirnova::printReverse(result.first, result.second);
    delete[] result.first;
    return 2;
  }

  smirnova::printReverse(result.first, result.second);
  delete[] result.first;
  return 0;
}
