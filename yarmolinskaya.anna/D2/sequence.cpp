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
}
