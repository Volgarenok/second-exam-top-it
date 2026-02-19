#include <iostream>

namespace alisov
{
  bool resize(char *&ans, size_t len, size_t &cap, size_t required)
  {
    size_t new_cap = (cap == 0) ? 1 : cap;

    while (new_cap < required)
      new_cap *= 2;

    char *new_ans = new (std::nothrow) char[new_cap];
    if (!new_ans)
      return false;

    for (size_t i = 0; i < len; ++i)
      new_ans[i] = ans[i];

    delete[] ans;
    ans = new_ans;
    cap = new_cap;
    return true;
  }
}

int main()
{
  char *ans = nullptr;
  size_t len = 0, cap = 0;
  size_t k;
  char ch;
  int exit_code = 0;

  while (true)
  {
    if (!(std::cin >> k))
    {
      if (!std::cin.eof())
      {
        std::cerr << "Cant read 1 of parameters" << '\n';
        exit_code = 1;
      }
      break;
    }

    if (!(std::cin >> ch))
    {
      std::cerr << "Cant read 1 of parameters" << '\n';
      exit_code = 1;
      break;
    }

    if (k == 0)
      continue;

    if (len + k > cap)
    {
      if (!alisov::resize(ans, len, cap, len + k))
      {
        std::cerr << "Memory allocation error" << '\n';
        delete[] ans;
        std::cout << '\n';
        return 2;
      }
    }

    for (size_t i = 0; i < k; ++i)
      ans[len++] = ch;
  }

  for (size_t i = len; i > 0; --i)
    std::cout << ans[i - 1];

  std::cout << '\n';

  delete[] ans;
  return exit_code;
}
