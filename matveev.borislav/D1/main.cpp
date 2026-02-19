#include <iostream>

int main()
{
  unsigned int b;
  char a;
  std::size_t max = 100000;
  char data[max];
  std::size_t sum = 0;

  while (std::cin >> b >> a)
  {
    for (unsigned int i = 0; i < b; ++i)
    {
      if (sum < max)
      {
        data[sum++] = a;
      }
    }
  }

  if (!std::cin.eof())
  {
    std::cerr << "input error\n";
    return 1;
  }
  for (std::size_t i = sum; i > 0; --i)
  {
    std::cout << data[i-1];
  }
  std::cout << '\n';
  return 0;
}
