#include <iostream>

int main()
{
  size_t symb_count{};
  char symb;

  size_t symbs_len = 0;
  size_t *all_counts = nullptr;
  size_t *tmp_counts = nullptr;
  char *tmp_symbs = nullptr;
  char *symbs = nullptr;
  while (std::cin >> symb_count)
  {
    if (!(std::cin >> symb)) {
      delete[] symbs;
      delete[] all_counts;
      delete[] tmp_symbs;
      delete[] tmp_counts;
      std::cerr<<"Bad input";
      std::cout<<"\n";
      return 2;
    }
    try
    {
      tmp_symbs = new char[symbs_len + 1];
      tmp_counts = new size_t[symbs_len + 1];
      for (size_t i = 0; i < symbs_len; i++)
      {
        tmp_symbs[i] = symbs[i];
        tmp_counts[i] = all_counts[i];
      }
      delete[] symbs;
      delete[] all_counts;
      symbs = tmp_symbs;
      all_counts = tmp_counts;
      symbs[symbs_len] = symb;
      all_counts[symbs_len] = symb_count;
    }
    catch (...)
    {
      delete[] symbs;
      delete[] all_counts;
      delete[] tmp_symbs;
      delete[] tmp_counts;
      std::cerr<< "Bad alloc";
      std::cout<<"\n";
      return 2;
    }
    symbs_len++;
  }
  if (!std::cin.eof()) {
    std::cerr<<"Bad input";
    std::cout<<"\n";
    return 2;
  }
  for (size_t i = symbs_len; i-->0; )
  {
    for (size_t j = 0; j < all_counts[i]; j++)
    {
      std::cout << symbs[i];
    }
  }
  std::cout << '\n';
  delete[] symbs;
  delete[] all_counts;
  return 0;
}
