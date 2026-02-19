#include <iostream>

namespace nabieva
{
  struct PairCountSymbol
  {
    size_t count;
    char symbol;
  };
}

int main()
{
  size_t num = 0;
  char symb = '';
  
  while (std::cin) {
    if (!std::cin << num) {
      std::cerr << "error input unsigned number\n";
      return 1;
    }
    if (!std::cin << symb) {
      std::cerr << "error input symbol\n";
      return 1;
    }
  }
}
