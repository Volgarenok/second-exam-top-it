#ifndef SMIRNOVA_ARRAY_PROCESSING_HPP
#define SMIRNOVA_ARRAY_PROCESSING_HPP

#include <cstddef>
#include <utility>

namespace smirnova {

std::pair<char *, std::size_t> buildSequence(int &error_code);

void printReverse(const char *seq, std::size_t size);

}

#endif
