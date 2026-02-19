#include <iostream>

namespace nabieva
{
  struct PairCountSymbol
  {
    size_t count;
    char symbol;
  };
  PairCountSymbol* addNewPair(PairCountSymbol* a, size_t countPair, size_t num, char symb)
  {
    PairCountSymbol* aNew = new PairCountSymbol[countPair + 1];
    for (size_t i = 0; i < countPair; i++) {
      aNew[i] = a[i];
    }
    aNew[countPair].count = num;
    aNew[countPair].symbol = symb;
    if (a != nullptr) {
      delete[] a;
    }
    return aNew;
  }
  void printPairs(const PairCountSymbol* pairs, size_t countPair)
  {
    for (size_t i = 0; i < countPair; i++) {
      for (size_t j = 0; j < pairs[countPair - i - 1].count; j++) {
        std::cout << pairs[countPair - i - 1].symbol;
      }
    }
    std::cout << "\n";
  }
}

int main()
{
  size_t num = 0;
  char symb = ' ';
  nabieva::PairCountSymbol* pairs = nullptr;
  size_t countPair = 0;
  while (true) {
    if (!(std::cin >> num) || !(std::cin >> symb)) {
      std::cerr << "error input unsigned number or symb\n";
      return 1;
    }
    if (std::cin.eof()) {
      nabieva::printPairs(pairs, countPair);
      delete[] pairs;
      break;
    }
    try {
      pairs = nabieva::addNewPair(pairs, countPair, num, symb);
      countPair++;
    }
    catch (const std::bad_alloc&) {
      nabieva::printPairs(pairs, countPair);
      delete[] pairs;
      return 2;
    }
  }
  return 0;
}
