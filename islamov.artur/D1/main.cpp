#include <iostream>
#include <new>

int main()
{
  char* buffer = new char[16];
  std::size_t cap = 16;
  std::size_t size = 0;
  unsigned int count = 0;
  char ch = '\0';
  while (std::cin >> count >> ch)
  {
    if (count == 0)
    {
      continue;
    }
    if (size + count > cap)
    {
      std::size_t new_cap = cap * 2;
      if (new_cap < size + count)
      {
        new_cap = size + count;
      }
      char* new_buffer = new char[new_cap];
      for (std::size_t i = 0; i < size; ++i)
      {
        new_buffer[i] = buffer[i];
      }
      delete[] buffer;
      buffer = new_buffer;
      cap = new_cap;
    }
    for (unsigned int i = 0; i < count; ++i)
    {
      buffer[size + i] = ch;
    }
    size += count;
  }
  if (size == 0)
  {
    std::cout << std::endl;
  }
  else
  {
    for (std::size_t i = size; i > 0; --i)
    {
      std::cout << buffer[i - 1];
    }
    std::cout << std::endl;
  }
  delete[] buffer;
  return 0;
}
