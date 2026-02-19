#ifndef ARGS_HPP
#define ARGS_HPP
#include <utility>

namespace yarmolinskaya {

std::pair< bool, bool > parseArgs(int argc, const char *const *argv);

}

#endif
