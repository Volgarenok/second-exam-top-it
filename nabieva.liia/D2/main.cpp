#include <iostream>
#include <cstring>

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

int main(int argc, char* argv[])
{
  if (argc > 1) {
    std::cerr << "Invalid arguments\n";
    return 1;
  }
  if (std::strcmp(argv[1], "reverse")) {
    std::cerr << "Invalid arguments\n";
    return 1;
  }
  char symb = ' ';
  nabieva::PairCountSymbol* pairs = nullptr;
  size_t countPair = 0;
  while (true) {
    if (!(std::cin >> symb)) {
      break;
    }
    if (std::cin.eof()) {
      break;
    }
    bool findSymb = false;
    for (size_t i = 0; i < countPair; i++) {
      if (pairs[i].symbol == symb) {
        pairs[i].count++;
        findSymb == true;
        break;
      }
    }
    if (findSymb == false) {
      pairs = nabieva::addNewPair(pairs, countPair, 1, symb);
      countPair++;
    }
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
    std::cout << pairs[i].count << " " << pairs[i].symbol << "\n";
  }
}