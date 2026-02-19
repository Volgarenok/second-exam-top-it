#include <iostream>

namespace nabieva
{
  struct PairCountSymbol
  {
    size_t count;
    char symbol;
  };
  PairCountSymbol* addNewPair(const PairCountSymbol* a, size_t countPair, size_t num, char symb);
  void printPairs(const PairCountSymbol* pairs, size_t countPair);
}

int main()
{
  size_t num = 0;
  char symb = ' ';
  nabieva::PairCountSymbol* pairs = nullptr;
  size_t countPair = 0;
  bool inputError = false;
  while (true) {
    if (!(std::cin >> num)) {
      if (std::cin.eof()) {
        break;
      }
      inputError = true;
      std::cerr << "error input unsigned number\n";
      break;
    }
    if (!(std::cin >> symb)) {
      if (std::cin.eof()) {
        std::cerr << "error incomplete pair\n";
      }
      else {
        std::cerr << "error input symb\n";
      }
      inputError = true;
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
  nabieva::printPairs(pairs, countPair);
  delete[] pairs;
  if (inputError == true) {
    return 1;
  }
  return 0;
}

nabieva::PairCountSymbol* nabieva::addNewPair(const nabieva::PairCountSymbol* a, size_t countPair, size_t num, char symb)
{
  nabieva::PairCountSymbol* aNew = new nabieva::PairCountSymbol[countPair + 1];
  for (size_t i = 0; i < countPair; i++) {
    aNew[i] = a[i];
  }
  aNew[countPair].count = num;
  aNew[countPair].symbol = symb;
  delete[] a;
  return aNew;
}
void nabieva::printPairs(const nabieva::PairCountSymbol* pairs, size_t countPair)
{
  for (size_t i = 0; i < countPair; i++) {
    for (size_t j = 0; j < pairs[countPair - i - 1].count; j++) {
      std::cout << pairs[countPair - i - 1].symbol;
    }
  }
  std::cout << "\n";
}
