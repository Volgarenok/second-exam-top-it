#include <iostream>
#include <cstddef>

namespace lukashevich
{
  struct char_pair
  {
    size_t count;
    char symbol;
  };

  bool read_symbols(char*& sym_arr, size_t& size_arr, size_t& count_sym)
  {
    count_sym = 0;
    size_arr = 10;
    sym_arr = new char[size_arr];

    char ch;
    std::cin >> std::skipws;

    while (std::cin >> ch)
    {
      if (count_sym >= size_arr)
      {
        size_t new_size = size_arr * 2;
        char* new_arr = new char[new_size];

        for (size_t i = 0; i < count_sym; ++i)
        {
          new_arr[i] = sym_arr[i];
        }

        delete[] sym_arr;
        sym_arr = new_arr;
        size_arr = new_size;
      }
      sym_arr[count_sym++] = ch;
    }

    std::cin >> std::noskipws;

    return true;
  }
}
int main()
{
  return 0;
}
