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

  int readSequence(std::istream& in, char*& data, size_t& size)
  {
    size_t count = 0;
    char ch = '\0';
    while (in >> count) {
      if (!(in >> ch)) {
        return 1;
      }
      if (!appendChars(data, size, ch, count)) {
        return 2;
      }
    }
    if (!in.eof()) {
      return 1;
    }
    return 0;
  }

  void printReversed(std::ostream& out, const char* data, size_t size)
  {
    for (size_t i = size; i > 0; --i) {
      out << data[i - 1];
    }
    out << '\n';
  }
}

int main()
{
  char* data = nullptr;
  size_t size = 0;
  gordejchik::readSequence(std::cin, data, size);
  gordejchik::printReversed(std::cout, data, size);
  gordejchik::freeSequence(data);
  return 0;
}
