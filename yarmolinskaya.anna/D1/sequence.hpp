#ifndef SEQUENCE_HPP
#define SEQUENCE_HPP
#include <cstddef>
#include <utility>

namespace yarmolinskaya {

struct sequence_t {
  char *data;
  std::size_t size;
  std::size_t capacity;
};
