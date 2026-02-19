#include <iostream>
#include <vector>
#include <stdexcept>

int main()
{
  std::vector<char> seq;
  unsigned int n;

  while (std::cin >> n)
  {
    char c;
    if (!(std::cin >> c))
    {
      std::cerr << "Error: не смогли прочитать элементы" << std::endl;
      for (int i = static_cast<int>(seq.size()) - 1; i >= 0; --i)
        std::cout << seq[i];
      std::cout << std::endl;
      return 1;
    }
    try
    {
      for (unsigned int i = 0; i < n; ++i)
        seq.push_back(c);
    }
    catch (const std::bad_alloc&)
    {
      std::cerr << "Error: не смогли выделить память" << std::endl;
      std::cout << std::endl;
      return 2;
    }
  }

  if (std::cin.fail() && !std::cin.eof())
  {
    std::cerr << "Error: не смогли прочитать число" << std::endl;
    for (int i = static_cast<int>(seq.size()) - 1; i >= 0; --i)
      std::cout << seq[i];
    std::cout << std::endl;
    return 1;
  }

  for (int i = static_cast<int>(seq.size()) - 1; i >= 0; --i)
    std::cout << seq[i];
  std::cout << std::endl;

  return 0;
}
