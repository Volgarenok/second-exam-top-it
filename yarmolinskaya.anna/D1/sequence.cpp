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

bool appendChars(sequence_t &seq, char ch, unsigned int count)
{
  const std::size_t newSize = seq.size + count;
  if (newSize > seq.capacity) {
    const std::size_t newCapacity = (newSize > seq.capacity * 2) ? newSize : seq.capacity * 2;
    char *newData = static_cast< char * >(std::realloc(seq.data, newCapacity));
    if (newData == nullptr) {
      return false;
    }
    seq.data = newData;
    seq.capacity = newCapacity;
  }
  std::memset(seq.data + seq.size, ch, count);
  seq.size = newSize;
  return true;
}

}
