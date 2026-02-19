#include <iostream>
#include <new>

int main()
{
  unsigned int b;
  char a;
  std::size_t sum = 0;
  char* data = nullptr;
  std::size_t cap = 0;
  bool input_error = false;

  while (true)
  {
    if (!(std::cin >> b))
    {
      break;
    }
    if (!(std::cin >> a))
    {
      input_error = true;
      break;
    }
    if (b == 0)
    {
      continue;
    }
    if (sum + b > cap)
    {
      std::size_t new_cap = (cap == 0) ? 1 : cap;
      while (new_cap < sum + b)
      {
        new_cap *= 2;
      }
      char* new_data = nullptr;
      try
      {
        new_data = new char[new_cap];
      }
      catch (const std::bad_alloc&)
      {
        delete[] data;
        std::cerr << "memory error\n";
        return 2;
      }

      for (std::size_t i = 0; i < sum; ++i)
      {
        new_data[i] = data[i];
      }

      delete[] data;
      data = new_data;
      cap = new_cap;
    }

    for (unsigned int i = 0; i < b; ++i)
    {
      data[sum++] = a;
    }
  }

  for (std::size_t i = sum; i > 0; --i)
  {
    std::cout << data[i - 1];
  }
  std::cout << '\n';
  delete[] data;
  if (input_error)
  {
    std::cerr << "input error\n";
    return 1;
  }
  return 0;
}

