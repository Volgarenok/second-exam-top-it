#include "sequence.hpp"
int main()
{
  using namespace musorin;
  pair_t* pairs = nullptr;
  size_t pairCount = 0;
  const int readResult = readPairs(pairs, pairCount);
  if (readResult == 1)
  {
    std::cerr << "Error: failed to read pair element\n";
    printLine("");
    return 1;
  }
  if (readResult == 2)
  {
    std::cerr << "Error: memory allocation failed\n";
    printLine("");
    return 2;
  }
  const size_t totalLength = calcTotalLength(pairs, pairCount);
  char* sequence = nullptr;
  try
  {
    sequence = new char[totalLength + 1];
  }
  catch (...)
  {
    delete[] pairs;
    std::cerr << "Error: memory allocation failed\n";
    printLine("");
    return 2;
  }
  buildSequence(pairs, pairCount, sequence);
  delete[] pairs;
  reverseString(sequence, totalLength);
  printLine(sequence);
  delete[] sequence;
  return 0;
}
