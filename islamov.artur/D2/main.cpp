#include <iostream>

int main(int argc, char* argv[])
{
  bool reverse = false;
  if (argc > 2)
  {
    std::cerr << "Invalid arguments\n";
    return 1;
  }
  if (argc == 2)
  {
    const char* arg = argv[1];
    const char* expect = "reverse";
    int i = 0;
    while (expect[i] != '\0' && arg[i] != '\0' && expect[i] == arg[i])
      ++i;
    if (expect[i] == '\0' && arg[i] == '\0')
      reverse = true;
    else
    {
      std::cerr << "Invalid argument\n";
      return 1;
    }
  }
  char* symb = new char[16];
  unsigned int* counts = new unsigned int[16];
  std::size_t cap = 16;
  std::size_t size = 0;
  char ch;
  while (std::cin >> ch)
  {
    std::size_t i = 0;
    while (i < size && symb[i] != ch)
      ++i;
    if (i < size)
      ++counts[i];
    else
    {
      if (size == cap)
      {
        std::size_t new_cap = cap * 2;
        char* new_symb = new char[new_cap];
        unsigned int* new_counts = new unsigned int[new_cap];
        for (std::size_t j = 0; j < size; ++j)
        {
          new_symb[j] = symb[j];
          new_counts[j] = counts[j];
        }
        delete[] symb;
        delete[] counts;
        symb = new_symb;
        counts = new_counts;
        cap = new_cap;
      }
      symb[size] = ch;
      counts[size] = 1;
      ++size;
    }
  }
  if (size == 0)
    std::cout << std::endl;
  else
  {
    if (!reverse)
      for (std::size_t i = 0; i < size; ++i)
        std::cout << counts[i] << ' ' << symb[i] << std::endl;
    else
      for (std::size_t i = size; i > 0; --i)
        std::cout << counts[i - 1] << ' ' << symb[i - 1] << std::endl;
  }
  delete[] symb;
  delete[] counts;
  return 0;
}
