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
  if (argc > 2) {
    std::cerr << "Invalid arguments\n";
    return 1;
  }
  if (argc == 2 && !(std::strcmp(argv[1], "reverse"))) {
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
      try {
        pairs = nabieva::addNewPair(pairs, countPair, 1, symb);
        countPair++;
      }
      catch (const std::bad_alloc&) {
        break;
      }
    }
  }
  if (argc == 2 && std::strcmp(argv[1], "reverse")) {
    nabieva::reversePrintPairs(pairs, countPair);
  }
  else {
    nabieva::printPairs(pairs, countPair);
  }
  delete[] pairs;
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
void nabieva::reversePrintPairs(const nabieva::PairCountSymbol* pairs, size_t countPair)
{
  for (size_t i = 0; i < countPair; i++) {
    std::cout << pairs[countPair - i - 1].count << " " << pairs[countPair - i - 1].symbol << "\n";
  }
}