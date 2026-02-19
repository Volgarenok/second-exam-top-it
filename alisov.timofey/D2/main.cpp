#include <iostream>
namespace alisov
{
  bool resize(char *&data, size_t size, size_t &cap)
  {
    size_t new_cap = (cap == 0) ? 1 : cap * 2;

    char *tmp = new (std::nothrow) char[new_cap];
    if (!tmp)
      return false;

    for (size_t i = 0; i < size; ++i)
      tmp[i] = data[i];

    delete[] data;
    data = tmp;
    cap = new_cap;
    return true;
  }
}
int main(int argc, char *argv[])
{
  bool reverse = false;

  if (argc > 2)
  {
    std::cerr << "Invalid arguments" << '\n';
    return 1;
  }

  if (argc == 2)
  {
    if (std::string(argv[1]) == "reverse")
      reverse = true;
    else
    {
      std::cerr << "Invalid arguments" << '\n';
      return 1;
    }
  }
  char *data = nullptr;
  size_t size = 0;
  size_t cap = 0;

  char ch;

  while (std::cin.get(ch))
  {
    if (std::isspace(static_cast< unsigned char >(ch)))
      continue;

    if (size == cap)
    {
      if (!alisov::resize(data, size, cap))
      {
        delete[] data;
        return 0;
      }
    }
    data[size++] = ch;
  }

  if (size == 0)
  {
    std::cout << '\n';
    delete[] data;
    return 0;
  }

  size_t *counts = new (std::nothrow) size_t[size];
  char *chars = new (std::nothrow) char[size];

  if (!counts || !chars)
  {
    delete[] data;
    delete[] counts;
    delete[] chars;
    return 0;
  }

  size_t groups = 0;

  for (size_t i = 0; i < size;)
  {
    char current = data[i];
    size_t count = 0;

    while (i < size && data[i] == current)
    {
      ++count;
      ++i;
    }

    counts[groups] = count;
    chars[groups] = current;
    ++groups;
  }
  if (!reverse)
  {
    for (size_t i = 0; i < groups; ++i)
      std::cout << counts[i] << " " << chars[i] << "\n";
  }
  else
  {
    for (size_t i = groups; i > 0; --i)
      std::cout << counts[i - 1] << " " << chars[i - 1] << "\n";
  }

  delete[] data;
  delete[] counts;
  delete[] chars;
}
