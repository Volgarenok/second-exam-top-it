#include "lab.hpp"

#include <cstring>
#include <iostream>

namespace smirnova {

namespace {

constexpr int MAX_CHARS = 256;

struct CharTable {
  int counts[MAX_CHARS];
  char order[MAX_CHARS];
  int orderSize;
};

bool isDelimiter(char ch)
{
  return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r';
}

void recordChar(CharTable & table, char ch)
{
  const int idx = static_cast<unsigned char>(ch);
  if (table.counts[idx] == 0) {
    table.order[table.orderSize] = ch;
    ++table.orderSize;
  }
  ++table.counts[idx];
}

bool readInput(CharTable & table)
{
  char ch = 0;
  while (std::cin.get(ch)) {
    if (!isDelimiter(ch)) {
      recordChar(table, ch);
    }
  }
  return std::cin.eof();
}

void printForward(const CharTable & table)
{
  for (int i = 0; i < table.orderSize; ++i) {
    const int idx = static_cast<unsigned char>(table.order[i]);
    std::cout << table.counts[idx] << ' ' << table.order[i] << '\n';
  }
}

void printReverse(const CharTable & table)
{
  for (int i = table.orderSize - 1; i >= 0; --i) {
    const int idx = static_cast<unsigned char>(table.order[i]);
    std::cout << table.counts[idx] << ' ' << table.order[i] << '\n';
  }
}

void printTable(const CharTable & table, bool reverse)
{
  if (table.orderSize == 0) {
    std::cout << '\n';
    return;
  }
  if (reverse) {
    printReverse(table);
  } else {
    printForward(table);
  }
}

}

bool parseArgs(int argc, char const * const * argv, ParseResult & result)
{
  result.reverse = false;
  if (argc == 1) {
    return true;
  }
  if (argc == 2 && std::strcmp(argv[1], "reverse") == 0) {
    result.reverse = true;
    return true;
  }
  return false;
}

bool processInput(bool reverse)
{
  CharTable table = {};
  const bool ok = readInput(table);
  if (ok) {
    printTable(table, reverse);
  }
  return ok;
}

}
