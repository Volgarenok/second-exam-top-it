#include <iostream>

namespace shigarev {

bool readPair(unsigned int & count, char & ch) {
  return static_cast< bool >(std::cin >> count >> ch);
}

}

int main() {
  unsigned int count = 0;
  char ch = '\0';
  if (shigarev::readPair(count, ch)) {
    std::cout << "count=" << count << " ch=" << ch << '\n';
  } else {
    std::cout << "no input\n";
  }
  return 0;
}
