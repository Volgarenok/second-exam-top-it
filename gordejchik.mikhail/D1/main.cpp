#include <iostream>
#include <cstddef>

namespace gordejchik
{
  void freeSequence(char*& data)
  {
    delete[] data;
    data = nullptr;
  }

  bool appendChars(char*& data, size_t& size, char ch, size_t count)
  {
    if (count == 0) {
      return true;
    }
    char* newData = nullptr;
    try {
      newData = new char[size + count];
    } catch (const std::bad_alloc&) {
      return false;
    }
    for (size_t i = 0; i < size; ++i) {
      newData[i] = data[i];
    }
    for (size_t i = 0; i < count; ++i) {
      newData[size + i] = ch;
    }
    delete[] data;
    data = newData;
    size += count;
    return true;
  }
}

int main()
{
  char* data = nullptr;
  size_t size = 0;
  gordejchik::appendChars(data, size, 'a', 2);
  gordejchik::freeSequence(data);
  return 0;
}
