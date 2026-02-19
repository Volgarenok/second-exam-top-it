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
}

int main()
{
  size_t num = 0;
  char symb = ' ';
  nabieva::PairCountSymbol* pairs = nullptr;
  size_t countPair = 0;
  while (std::cin) {
    if (!std::cin >> num) {
      std::cerr << "error input unsigned number\n";
      return 1;
    }
    if (!std::cin >> symb) {
      std::cerr << "error input symbol\n";
      return 1;
    }
    pairs = nabieva::addNewPair(pairs, countPair, num, symb);
  }
}
