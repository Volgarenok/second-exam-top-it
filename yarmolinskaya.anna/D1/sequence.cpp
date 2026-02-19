#include "sequence.hpp"
#include <cstdlib>
#include <cstring>

namespace yarmolinskaya {

  sequence_t createSequence()
  {
    return sequence_t{nullptr, 0, 0};
  }
}
