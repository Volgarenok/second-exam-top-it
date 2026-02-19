#include <iostream>

namespace novikov {
  struct pair_t {
    size_t count;
    char symbol;
  };
  bool strEqual(const char * a, const char * b);
  void extend(pair_t ** seq, size_t capacity, size_t newCapacity);
  void destroy(pair_t ** seq);
  int readInput(pair_t ** pairs, size_t * size, size_t * capacity);
  void printPairs(const pair_t * pairs, size_t size, bool reverse);
}

int main(int argc, char ** argv)
{
  using namespace novikov;
  if (argc != 1 && (argc != 2 || !strEqual(argv[1], "reverse"))) {
    std::cerr << "invalid arguments\n";
    return 1;
  }
  const bool reverse = (argc == 2);
  pair_t * pairs = nullptr;
  size_t size = 0;
  size_t capacity = 0;
  int result = readInput(&pairs, &size, &capacity);
  if (result == 0) {
    printPairs(pairs, size, reverse);
  }
  destroy(&pairs);
  if (result == 1) {
    std::cerr << "read error\n";
  } else if (result == 2) {
    std::cerr << "bad alloc\n";
  }
  return result;
}

bool novikov::strEqual(const char * a, const char * b)
{
  while (*a && *b) {
    if (*a != *b) {
      return false;
    }
    ++a;
    ++b;
  }
  return *a == *b;
}

void novikov::extend(pair_t ** seq, const size_t capacity, const size_t newCapacity)
{
  pair_t * newSeq = new pair_t[newCapacity];
  for (size_t i = 0; i < capacity; ++i) {
    newSeq[i] = (*seq)[i];
  }
  delete [] (*seq);
  *seq = newSeq;
}

void novikov::destroy(pair_t ** seq)
{
  delete [] (*seq);
  *seq = nullptr;
}

int novikov::readInput(pair_t ** pairs, size_t * size, size_t * capacity)
{
  char symbol = 0;
  while (std::cin >> symbol) {
    if (*size > 0 && (*pairs)[*size - 1].symbol == symbol) {
      (*pairs)[*size - 1].count++;
    } else {
      if (*size == *capacity) {
        size_t newCapacity = 0;
        if (*capacity == 0) {
          newCapacity = 1;
        } else {
          newCapacity = (*capacity) * 2;
        }
        try {
          extend(pairs, *capacity, newCapacity);
        } catch (const std::bad_alloc &) {
          return 2;
        }
        *capacity = newCapacity;
      }
      (*pairs)[*size].symbol = symbol;
      (*pairs)[*size].count = 1;
      (*size)++;
    }
  }
  if (!std::cin.eof()) {
    return 1;
  }
  return 0;
}

void novikov::printPairs(const pair_t * pairs, const size_t size, const bool reverse)
{
  if (size == 0) {
    std::cout << "\n";
    return;
  }
  if (reverse) {
    for (size_t i = size; i > 0; --i) {
      std::cout << pairs[i - 1].count << " " << pairs[i - 1].symbol << "\n";
    }
  } else {
    for (size_t i = 0; i < size; ++i) {
      std::cout << pairs[i].count << " " << pairs[i].symbol << "\n";
    }
  }
}
