#include <iostream>
namespace alisov
{
  bool resize(char *&ans, size_t &len, size_t &cap)
  {
    char *new_ans = new char[cap * 2];
    for (size_t i = 0; i < len; ++i)
    {
      new_ans[i] = ans[i];
    }
    delete[] ans;
    ans = new_ans;
    cap *= 2;
    return true;
  }
}
int main()
{
  char *ans = nullptr;
  size_t len = 0, cap = 1;
  size_t k;
  char ch;

  while (true)
  {
    if (!(std::cin >> k))
    {
      if (std::cin.eof())
      {
        std::cout << "";
        break;
      }
      else
      {
        std::cerr << "Cant read 1 of parameters" << '\n';
        std::cout << "";
        delete[] ans;
        return 1;
      }
    }
    if (!(std::cin >> ch))
    {
      std::cerr << "Cant read 1 of parameters" << '\n';
      std::cout << "";
      delete[] ans;
      return 1;
    }
    if (k == 0)
    {
      continue;
    }
    if (len + k > cap)
    {
      if (!alisov::resize(ans, len, cap))
      {
        std::cerr << "Cant resize array" << '\n';
        std::cout << "";
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
