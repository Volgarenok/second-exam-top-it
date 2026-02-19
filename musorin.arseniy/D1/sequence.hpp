#ifndef SEQUENCE_HPP
#define SEQUENCE_HPP
#include <iostream>
namespace musorin {
  struct pair_t
  {
    size_t count;
    char symbol;
  };
  int readPairs(pair_t*& pairs, size_t& pairCount);
  size_t calcTotalLength(const pair_t* pairs, size_t pairCount);
  void buildSequence(const pair_t* pairs, size_t pairCount, char* result);
  void reverseString(char* str, size_t length);
  void printLine(const char* str);
  int buildAndPrint(pair_t* pairs, size_t pairCount);
}
#endif
