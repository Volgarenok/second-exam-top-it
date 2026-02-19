#include <iostream>

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

  char* extend(const char* oldArray, std::size_t oldSize, char symbol)
  {
    char* newArray = nullptr;
    try
    {
      newArray = new char[oldSize + 1];
    }
    catch (const std::bad_alloc&)
    {
      return nullptr;
    }
    for (std::size_t i = 0; i < oldSize; ++i)
    {
      newArray[i] = oldArray[i];
    }
    newArray[oldSize] = symbol;
    return newArray;
  }

  void reverseSequence(char* seq, std::size_t size)
  {
    if (size == 0)
    {
      return;
    }
    std::size_t left = 0;
    std::size_t right = size - 1;
    while (left < right)
    {
      const char temp = seq[left];
      seq[left] = seq[right];
      seq[right] = temp;
      left = left + 1;
      right = right - 1;
    }
  }

  void cleanup(char* seq)
  {
    delete[] seq;
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

  char* seq = nullptr;
  std::size_t seqSize = 0;

  parsov::cleanup(seq);
  return 0;
}
