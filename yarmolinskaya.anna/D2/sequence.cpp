#include "sequence.hpp"

#include <cstdlib>
#include <cstring>

namespace yarmolinskaya {

sequence_t createSequence()
{
  return sequence_t{nullptr, 0, 0};
}

void destroySequence(sequence_t &seq)
{
  std::free(seq.data);
  seq.data = nullptr;
  seq.size = 0;
  seq.capacity = 0;
}

bool appendChar(sequence_t &seq, char ch)
{
  if (seq.size == seq.capacity) {
    const std::size_t newCapacity = (seq.capacity == 0) ? 8 : seq.capacity * 2;
    char *newData = static_cast< char * >(std::realloc(seq.data, newCapacity));
    if (newData == nullptr) {
      return false;
    }
    seq.data = newData;
    seq.capacity = newCapacity;
  }
  seq.data[seq.size] = ch;
  seq.size += 1;
  return true;
}

}
