#include <iostream>
#include <cstddef>
#include <utility>
#include <new>

namespace parsov
{
  bool isEqual(const char* str1, const char* str2)
  {
    std::size_t i = 0;
    while (str1[i] != '\0' && str2[i] != '\0')
    {
      if (str1[i] != str2[i])
      {
        return false;
      }
      i = i + 1;
    }
    return str1[i] == str2[i];
  }

  std::pair<unsigned int, char>* extend(const std::pair<unsigned int, char>* oldArray, std::size_t oldSize, const std::pair<unsigned int, char>& newPair)
  {
    std::pair<unsigned int, char>* newArray = nullptr;
    try
    {
      newArray = new std::pair<unsigned int, char>[oldSize + 1];
    }
    catch (const std::bad_alloc&)
    {
      return nullptr;
    }
    for (std::size_t i = 0; i < oldSize; ++i)
    {
      newArray[i] = oldArray[i];
    }
    newArray[oldSize] = newPair;
    return newArray;
  }

  void reversePairs(std::pair<unsigned int, char>* pairs, std::size_t size)
  {
    if (size == 0)
    {
      return;
    }
    std::size_t left = 0;
    std::size_t right = size - 1;
    while (left < right)
    {
      const std::pair<unsigned int, char> temp = pairs[left];
      pairs[left] = pairs[right];
      pairs[right] = temp;
      left = left + 1;
      right = right - 1;
    }
  }
}

int main(int argc, char** argv)
{
  bool isReverse = false;

  if (argc == 2)
  {
    if (parsov::isEqual(argv[1], "reverse"))
    {
      isReverse = true;
    }
    else
    {
      std::cerr << "invalid argument\n";
      return 1;
    }
  }
  else if (argc > 2)
  {
    std::cerr << "too many arguments\n";
    return 1;
  }

  std::pair<unsigned int, char>* pairs = nullptr;
  std::size_t pairsSize = 0;

  char symbol = '\0';
  if (std::cin >> symbol)
  {
    char currentChar = symbol;
    unsigned int currentCount = 1;

    while (std::cin >> symbol)
    {
      if (symbol == currentChar)
      {
        currentCount = currentCount + 1;
      }
      else
      {
        std::pair<unsigned int, char>* newPairs = parsov::extend(pairs, pairsSize, std::pair<unsigned int, char>(currentCount, currentChar));
        if (!newPairs)
        {
          std::cerr << "failed to allocate memory\n";
          std::cout << "\n";
          delete[] pairs;
          return 2;
        }
        delete[] pairs;
        pairs = newPairs;
        pairsSize = pairsSize + 1;

        currentChar = symbol;
        currentCount = 1;
      }
    }

    std::pair<unsigned int, char>* newPairs = parsov::extend(pairs, pairsSize, std::pair<unsigned int, char>(currentCount, currentChar));
    if (!newPairs)
    {
      std::cerr << "failed to allocate memory\n";
      std::cout << "\n";
      delete[] pairs;
      return 2;
    }
    delete[] pairs;
    pairs = newPairs;
    pairsSize = pairsSize + 1;
  }

  if (isReverse)
  {
    parsov::reversePairs(pairs, pairsSize);
  }

  for (std::size_t i = 0; i < pairsSize; ++i)
  {
    std::cout << pairs[i].first << " " << pairs[i].second << "\n";
  }

  if (pairsSize == 0)
  {
    std::cout << "\n";
  }

  delete[] pairs;
  return 0;
}
