#include <iostream>

namespace parsov
{
}

int main()
{
  while (true)
  {
    unsigned int count = 0;
    if (!(std::cin >> count))
    {
      if (std::cin.eof())
      {
        break;
      }
      std::cerr << "failed to read count\n";
      return 1;
    }

    char symbol = '\0';
    if (!(std::cin >> symbol))
    {
      std::cerr << "failed to read symbol\n";
      return 1;
    }
  }

  std::cout << "\n";
  return 0;
}
