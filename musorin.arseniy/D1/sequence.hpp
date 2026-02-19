// sequence.hpp
#ifndef SEQUENCE_HPP
#define SEQUENCE_HPP
#include <iostream>
namespace musorin {
  struct pair_t
  {
    unsigned int count;
    char symbol;
  };
  int readPairs(pair_t*& pairs, std::size_t& pairCount);
  std::size_t calcTotalLength(const pair_t* pairs, std::size_t pairCount);
  void buildSequence(const pair_t* pairs, std::size_t pairCount, char* result);
  void reverseString(char* str, std::size_t length);
  void printLine(const char* str);
}
#endif
