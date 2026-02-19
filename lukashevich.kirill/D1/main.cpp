#include <iostream>
#include <cstddef>

namespace lukashevich
{
  struct char_pair {
    size_t count;
    char symbol;
  };

  bool read_pair(char_pair*& pair_arr, size_t& size_arr, size_t& count_pair)
  {
    count_pair = 0;
    size_arr = 10;

    pair_arr = new char_pair [size_arr];

    while (true)
    {
      char_pair pair;
      if (!(std::cin >> pair.count))
      {
        if (std::cin.eof())
        {
          break;
        }
        delete [] pair_arr;
        return false;
      }

      if (!(std::cin >> pair.symbol))
      {
        delete [] pair_arr;
        return false;
      }

      if (count_pair >= size_arr)
      {
        size_t new_size = size_arr * 2;
        char_pair* new_arr = new char_pair [new_size];

        for (size_t i = 0; i < count_pair; ++i)
        {
          new_arr[i] = pair_arr[i];
        }

        delete [] pair_arr;
        pair_arr = new_arr;
        size_arr = new_size;
      }
    }
  }
}
int main()
{
  return 0;
}
