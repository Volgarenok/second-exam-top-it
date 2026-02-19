#include <iostream>

namespace krivoshapov
{
  struct DynArray
  {
    char *data;
    size_t size;
    size_t capacity;

    DynArray() : data(nullptr), size(0), capacity(0) {}
    ~DynArray() { delete[] data; }

    bool push_back(char c)
    {
      if (size == capacity)
      {
        size_t new_cap = (capacity == 0) ? 8 : capacity * 2;
        try
        {
          char *new_data = new char[new_cap];
          for (size_t i = 0; i < size; ++i)
            new_data[i] = data[i];
          delete[] data;
          data = new_data;
          capacity = new_cap;
        }
        catch (std::bad_alloc &)
        {
          return false;
        }
      }
      data[size++] = c;
      return true;
    }

    size_t get_size() const { return size; }
    const char *get_data() const { return data; }
  };
}

int main()
{
  krivoshapov::DynArray arr;
  unsigned int count;
  char ch;

  while (std::cin >> count)
  {
    if (!(std::cin >> ch))
    {
      std::cerr << "Failed to read character\n";
      return 1;
    }
    for (unsigned int i = 0; i < count; ++i)
    {
      if (!arr.push_back(ch))
      {
        std::cout << std::endl;
        std::cerr << "Memory allocation failed\n";
        return 2;
      }
    }
  }

  if (!std::cin.eof() && std::cin.fail())
  {
    std::cerr << "Failed to read count\n";
    return 1;
  }

  for (size_t i = arr.get_size(); i > 0; --i)
  {
    std::cout << arr.get_data()[i - 1];
  }
  std::cout << std::endl;

  return 0;
}
