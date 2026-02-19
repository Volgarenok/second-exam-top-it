#include <iostream>
#include <new>
#include <limits>

int main()
{
  char* buffer = nullptr;
  std::size_t cap = 0;
  std::size_t size = 0;
  try
  {
    buffer = new char[16];
    cap = 16;
  }
  catch (const std::bad_alloc&)
  {
    std::cerr << "Memory allocation error\n";
    return 2;
  }
  unsigned int count = 0;
  char ch = '\0';
  while (std::cin >> count >> ch)
  {
    if (count == 0)
    {
      continue;
    }
    if (size > std::numeric_limits< std::size_t >::max() - count)
    {
      delete[] buffer;
      std::cerr << "Error: too many characters requested\n";
      return 2;
    }
    if (size + count > cap)
    {
      std::size_t new_cap = cap * 2;
      if (new_cap < size + count)
      {
        new_cap = size + count;
      }
      char* new_buffer = nullptr;
      try
      {
        new_buffer = new char[new_cap];
      }
      catch (const std::bad_alloc&)
      {
        delete[] buffer;
        std::cerr << "Memory allocation error\n";
        return 2;
      }
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
  if (!std::cin.eof())
  {
    delete[] buffer;
    std::cerr << "Input error\n";
    return 1;
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
