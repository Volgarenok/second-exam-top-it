#include "args.hpp"
#include "io.hpp"
#include "sequence.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
  const auto argsResult = yarmolinskaya::parseArgs(argc, argv);
  const bool argsOk = argsResult.first;
  const bool reverse = argsResult.second;

  if (!argsOk) {
    std::cerr << "Error: invalid arguments\n"
              << "Usage: ./lab [reverse]\n";
    return 1;
  }

  yarmolinskaya::sequence_t seq = yarmolinskaya::createSequence();

  if (!yarmolinskaya::readSequence(seq)) {
    yarmolinskaya::destroySequence(seq);
    std::cerr << "Error: memory allocation failed\n";
    return 2;
  }

  yarmolinskaya::printPairs(seq, reverse);
  yarmolinskaya::destroySequence(seq);
  return 0;
}
