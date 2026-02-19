#include <iostream>

namespace novikov {
  void extend(char ** seq, size_t capacity, size_t newCapacity);
  void destroy(char ** seq);
  void printReversed(const char * seq, size_t size);
  int readInput(char ** seq, size_t * size, size_t * capacity);
}

int main()
{
  using namespace novikov;
  char * seq = nullptr;
  size_t size = 0;
  size_t capacity = 0;
  int result = readInput(&seq, &size, &capacity);
  printReversed(seq, size);
  destroy(&seq);
  if (result == 1) {
    std::cerr << "read error\n";
  } else if (result == 2) {
    std::cerr << "bad alloc\n";
  }
  return result;
}

void novikov::extend(char ** seq, size_t capacity, size_t newCapacity)
{
  char * newSeq = new char[newCapacity];
  for (size_t i = 0; i < capacity; ++i) {
    newSeq[i] = (*seq)[i];
  }
  delete [] (*seq);
  *seq = newSeq;
}

void novikov::destroy(char ** seq)
{
  delete [] (*seq);
  *seq = nullptr;
}

void novikov::printReversed(const char * seq, size_t size)
{
  for (size_t i = size; i > 0; --i) {
    std::cout << seq[i - 1];
  }
  std::cout << "\n";
}

int novikov::readInput(char ** seq, size_t * size, size_t * capacity)
{
  while (std::cin) {
    size_t count = 0;
    std::cin >> count;
    if (!std::cin) {
      if (std::cin.eof()) {
        break;
      }
      return 1;
    }
    char symbol = 0;
    std::cin >> symbol;
    if (!std::cin) {
      return 1;
    }
    for (size_t i = 0; i < count; ++i) {
      if (*size == *capacity) {
        size_t newCapacity = 0;
        if (*capacity == 0) {
          newCapacity = 1;
        } else {
          newCapacity = (*capacity) * 2;
        }
        try {
          extend(seq, *capacity, newCapacity);
        } catch (const std::bad_alloc &) {
          return 2;
        }
        *capacity = newCapacity;
      }
      (*seq)[(*size)++] = symbol;
    }
  }
  return 0;
}
