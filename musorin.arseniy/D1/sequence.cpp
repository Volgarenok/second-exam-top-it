#include "sequence.hpp"
int musorin::readPairs(pair_t*& pairs, size_t& pairCount)
{
  const size_t initialCapacity = 8;
  size_t capacity = initialCapacity;
  pairCount = 0;
  try
  {
    pairs = new pair_t[capacity];
  }
  catch (...)
  {
    pairs = nullptr;
    return 2;
  }
  size_t count = 0;
  char symbol = 0;
  while (std::cin >> count)
  {
    if (!(std::cin >> symbol))
    {
      delete[] pairs;
      pairs = nullptr;
      return 1;
    }
    if (pairCount == capacity)
    {
      const size_t newCapacity = capacity * 2;
      pair_t* newPairs = nullptr;
      try
      {
        newPairs = new pair_t[newCapacity];
      }
      catch (...)
      {
        delete[] pairs;
        pairs = nullptr;
        return 2;
      }
      for (size_t i = 0; i < pairCount; ++i)
      {
        newPairs[i] = pairs[i];
      }
      delete[] pairs;
      pairs = newPairs;
      capacity = newCapacity;
    }
    pairs[pairCount].count = count;
    pairs[pairCount].symbol = symbol;
    ++pairCount;
  }
  if (!std::cin.eof())
  {
    delete[] pairs;
    pairs = nullptr;
    return 1;
  }
  return 0;
}
size_t musorin::calcTotalLength(const pair_t* pairs,
    const size_t pairCount)
{
  size_t total = 0;
  for (size_t i = 0; i < pairCount; ++i)
  {
    total += pairs[i].count;
  }
  return total;
}
void musorin::buildSequence(const pair_t* pairs,
    const size_t pairCount, char* result)
{
  size_t pos = 0;
  for (size_t i = 0; i < pairCount; ++i)
  {
    for (size_t j = 0; j < pairs[i].count; ++j)
    {
      result[pos] = pairs[i].symbol;
      ++pos;
    }
  }
  result[pos] = '\0';
}
void musorin::reverseString(char* str, const size_t length)
{
  if (length == 0)
  {
    return;
  }
  size_t left = 0;
  size_t right = length - 1;
  while (left < right)
  {
    const char tmp = str[left];
    str[left] = str[right];
    str[right] = tmp;
    ++left;
    --right;
  }
}
void musorin::printLine(const char* str)
{
  std::cout << str << "\n";
}
