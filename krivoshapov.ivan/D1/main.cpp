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
  }
}
int main()
{
}
