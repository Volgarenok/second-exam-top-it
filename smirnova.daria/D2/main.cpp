#include "lab.hpp"

#include <iostream>

int main(int argc, char * argv[])
{
  smirnova::ParseResult args = {};
  if (!smirnova::parseArgs(argc, const_cast<char const * const *>(argv), args)) {
    std::cerr << "Usage: ./lab [reverse]\n";
    return 1;
  }
  if (!smirnova::processInput(args.reverse)) {
    std::cerr << "Input read error\n";
    return 2;
  }
  return 0;
}
