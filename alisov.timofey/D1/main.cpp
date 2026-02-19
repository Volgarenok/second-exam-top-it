#include <iostream>
namespace alisov
{
  bool resize(char *&ans, size_t &len, size_t &cap, size_t k)
  {
    size_t new_cap = cap * 2;
    if (new_cap < len + k)
    {
      new_cap = len + k;
    }
    char *new_ans = new char[new_cap];
    for (size_t i = 0; i < len; ++i)
    {
      new_ans[i] = ans[i];
    }
    delete[] ans;
    ans = new_ans;
    cap = new_cap;
    return true;
  }
}
int main()
{
  char *ans = nullptr;
  size_t len = 0, cap = 1;
  size_t k;
  char ch;
  try
  {
    ans = new char[16];
    cap = 16;
  }
  catch (const std::bad_alloc &)
  {
    std::cerr << "Memory allocation error\n";
    return 2;
  }

  while (true)
  {
    if (!(std::cin >> k))
    {
      if (std::cin.eof())
      {
        break;
      }
      delete[] ans;
      return 1;
    }
    if (!(std::cin >> ch))
    {
      std::cerr << "Cant read 1 of parameters" << '\n';
      delete[] ans;
      return 1;
    }
    if (k == 0)
    {
      continue;
    }
    if (len + k > cap)
    {
      if (!alisov::resize(ans, len, cap, k))
      {
        std::cerr << "Cant resize array" << '\n';
        delete[] ans;
        return 2;
      }
    }
    for (size_t i = 0; i < k; ++i)
    {
      ans[len++] = ch;
    }
  }
  for (std::size_t i = len; i > 0; --i)
  {
    std::cout << ans[i - 1];
  }

  delete[] ans;
}
