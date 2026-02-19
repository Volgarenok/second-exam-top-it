#include <iostream>

namespace novikov {
  void extend(char ** seq, size_t capacity, size_t newCapacity);
  void destroy(char ** seq);
  void printReversed(const char * seq, size_t size);
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
