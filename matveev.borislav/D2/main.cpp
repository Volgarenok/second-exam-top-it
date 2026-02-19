#include <iostream>
#include <new>
#include <cctype>

int main(int argc, char* argv[])
{
  bool reverse = false;
  if (argc == 1)
  {
  }
  else if (argc == 2)
  {
    const char* arg = argv[1];
    if (arg[0] == 'r' &&
        arg[1] == 'e' &&
        arg[2] == 'v' &&
        arg[3] == 'e' &&
        arg[4] == 'r' &&
        arg[5] == 's' &&
        arg[6] == 'e' &&
        arg[7] == '\0')
    {
      reverse = true;
    }
    else
    {
      std::cerr << "invalid arguments\n";
      return 1;
    }
  }
  else
  {
    std::cerr << "invalid arguments\n";
    return 1;
  }

  char* data = nullptr;
  std::size_t* counts = nullptr;
  std::size_t size = 0;
  std::size_t cap = 0;
  char now = 0;
  std::size_t now_count = 0;
  bool now_has = false;
  char c;
  while (std::cin.get(c))
  {
    if (std::isspace(static_cast<unsigned char>(c)))
    {
      continue;
    }

    if (!now_has)
    {
      now = c;
      now_count = 1;
      now_has = true;
    }
    else if (c == now)
    {
      ++now_count;
    }
    else
    {
      if (size == cap)
      {
        std::size_t new_cap = (cap == 0) ? 1 : cap * 2;

        char* new_data = nullptr;
        std::size_t* new_counts = nullptr;

        try
        {
          new_data = new char[new_cap];
          new_counts = new std::size_t[new_cap];
        }
        catch (const std::bad_alloc&)
        {
          delete[] data;
          delete[] counts;
          std::cerr << "memory error\n";
          return 2;
        }

        for (std::size_t i = 0; i < size; ++i)
        {
          new_data[i] = data[i];
          new_counts[i] = counts[i];
        }

        delete[] data;
        delete[] counts;

        data = new_data;
        counts = new_counts;
        cap = new_cap;
      }
      data[size] = now;
      counts[size] = now_count;
      ++size;
      now = c;
      now_count = 1;
    }
  }

  if (now_has)
  {
    if (size == cap)
    {
      std::size_t new_cap = (cap == 0) ? 1 : cap * 2;

      char* new_data = nullptr;
      std::size_t* new_counts = nullptr;

      try
      {
        new_data = new char[new_cap];
        new_counts = new std::size_t[new_cap];
      }
      catch (const std::bad_alloc&)
      {
        delete[] data;
        delete[] counts;
        std::cerr << "memory error\n";
        return 2;
      }

      for (std::size_t i = 0; i < size; ++i)
      {
        new_data[i] = data[i];
        new_counts[i] = counts[i];
      }

      delete[] data;
      delete[] counts;

      data = new_data;
      counts = new_counts;
      cap = new_cap;
    }

    data[size] = now;
    counts[size] = now_count;
    ++size;
  }

  if (size == 0)
  {
    std::cout << '\n';
    delete[] data;
    delete[] counts;
    return 0;
  }

  if (!reverse)
  {
    for (std::size_t i = 0; i < size; ++i)
    {
      std::cout << counts[i] << ' ' << data[i] << '\n';
    }
  }
  else
  {
    for (std::size_t i = size; i > 0; --i)
    {
      std::cout << counts[i - 1] << ' ' << data[i - 1] << '\n';
    }
  }

  delete[] data;
  delete[] counts;

  return 0;
}
