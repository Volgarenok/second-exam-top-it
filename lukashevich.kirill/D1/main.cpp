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
      pair_arr[count_pair] = pair;
      ++count_pair;
    }
    return true;
  }

  char* build_seq(const char_pair* pairs, size_t count_pairs, size_t& total_len)
  {
    total_len = 0;
    for (size_t i = 0; i < count_pairs; ++i)
    {
      total_len += pairs[i].count;
    }

    char* seq = new char [total_len + 1];

    size_t pos = 0;
    for (size_t i = 0; i < count_pairs; ++i)
    {
      for (size_t k = 0; k < pairs[i].count; ++k)
      {
        seq[pos++] = pairs[i].symbol;
      }
    }
    seq[total_len] = '\0';

    return seq;
  }

  void print_seq(const char* seq, size_t len)
  {
    for (size_t i = len; i > 0; i--)
    {
      std::cout << seq[i-1];
    }
    std::cout << "\n";
  }

  int proc()
  {
    char_pair* pairs = nullptr;
    size_t arr_size = 0, pairs_count = 0;
    try {
      if (!read_pair(pairs, arr_size, pairs_count))
      {
        std::cerr << "error input" << "\n";
        std::cout << "\n";
        return 1;
      }
    } catch(const std::bad_alloc&) {
      std::cerr << "error memory" << "\n";
      delete [] pairs;
      std::cout << "\n";
      return 2;
    }

    if (pairs_count == 0)
  {
    delete [] pairs;
    std::cout << "\n";
    return 1;
  }

    size_t seq_len = 0;
    char* seq = nullptr;

    try {
      seq = build_seq(pairs, pairs_count, seq_len);
    } catch (const std::bad_alloc&) {
      std::cerr << "error memory" << "\n";
      std::cout << "\n";
      delete [] pairs;
      return 2;
    }

    delete [] pairs;

    print_seq(seq, seq_len);

    delete [] seq;

    return 0;
  }
}


int main()
{
  return lukashevich::proc();
}
