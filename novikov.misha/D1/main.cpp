#include <iostream>

namespace novikov {
  void extend(char ** seq, size_t capacity, size_t newCapacity);
  void destroy(char ** seq);
  void printReversed(const char * seq, size_t size);
  int readInput(char ** seq, size_t * size, size_t * capacity);
}

int main()
{
  return 0;
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
  for (size_t i = 0; i = size; i > 0; --i) {
    std::cout << seq[i - 1];
  }
  std::cout << "\n";
}

int novikov::readInput(char ** seq, size_t * size, size_t * capacity)
{
  while (std::cin) {
    size_t count = 0;
    char symbol = 0;
    std::cin >> count >> symbol;
    if (!std::cin) {
      if (std::cin.eof()) {
        break;
      }
      return 1;
    }
    for (size_t i = 0; i < count; ++i) {
      if (*size == *capacity) {
        size_t newCapacity = (*capacity == 0) ? 1 : (*capacity) * 2;
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
