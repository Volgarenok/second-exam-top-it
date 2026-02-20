#include "sequence.hpp"
int main()
{
  using namespace musorin;
  pair_t* pairs = nullptr;
  size_t pairCount = 0;
  const int readResult = readPairs(pairs, pairCount);
  if (readResult == 1)
  {
    const int printResult = buildAndPrint(pairs, pairCount);
    std::cerr << "Error: failed to read pair element\n";
    if (printResult == 2)
    {
      return 2;
    }
    return 1;
  }
  if (readResult == 2)
  {
    const int printResult = buildAndPrint(pairs, pairCount);
    std::cerr << "Error: memory allocation failed\n";
    if (printResult == 2)
    {
      return 2;
    }
    return 2;
  }
  const int printResult = buildAndPrint(pairs, pairCount);
  if (printResult == 2)
  {
    std::cerr << "Error: memory allocation failed\n";
    return 2;
  }
  return 0;
}
