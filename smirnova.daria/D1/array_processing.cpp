#include "array_processing.hpp"

#include <iostream>
#include <new>

static char *growBuffer(const char *buf, std::size_t size, std::size_t new_cap)
{
  char *new_buf = new(std::nothrow) char[new_cap];
  if (new_buf == nullptr) {
    return nullptr;
  }
  for (std::size_t i = 0; i < size; ++i) {
    new_buf[i] = buf[i];
  }
  return new_buf;
}

std::pair<char *, std::size_t> smirnova::buildSequence(int &error_code)
{
  error_code = 0;
  const std::size_t initial_capacity = 16;
  std::size_t capacity = initial_capacity;
  std::size_t size = 0;
  char *seq = new(std::nothrow) char[capacity];
  if (seq == nullptr) {
    error_code = 2;
    return {nullptr, 0};
  }

  unsigned int count = 0;
  char ch = '\0';
  while (std::cin >> count) {
    if (!(std::cin >> ch)) {
      delete[] seq;
      error_code = 1;
      return {nullptr, 0};
    }
    if (size + count > capacity) {
      std::size_t new_cap = capacity;
      while (new_cap < size + count) {
        new_cap *= 2;
      }
      char *new_seq = growBuffer(seq, size, new_cap);
      if (new_seq == nullptr) {
        delete[] seq;
        error_code = 2;
        return {nullptr, 0};
      }
      delete[] seq;
      seq = new_seq;
      capacity = new_cap;
    }
    for (unsigned int i = 0; i < count; ++i) {
      seq[size] = ch;
      ++size;
    }
  }

  if (!std::cin.eof()) {
    delete[] seq;
    error_code = 1;
    return {nullptr, 0};
  }

  return {seq, size};
}
