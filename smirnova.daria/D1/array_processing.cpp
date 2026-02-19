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
