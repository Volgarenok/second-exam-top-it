#include <iostream>

int main()
{
  unsigned int b;
  char a;
  while (std::cin >> b >> a)
  {
    while (b)
    {
      std::cout << a;
      --b;
    }
    std::cout << "\n";
  }

  if (!std::cin.eof())
  {
    std::cerr << "Input error\n";
    return 1;
  }
  return 0;
}
