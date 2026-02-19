#include "args.hpp"
#include <cstring>

namespace yarmolinskaya {

std::pair< bool, bool > parseArgs(int argc, const char *const *argv)
{
  if (argc == 1) {
    return {true, false};
  }
  if (argc == 2 && std::strcmp(argv[1], "reverse") == 0) {
    return {true, true};
  }
  return {false, false};
}

}
