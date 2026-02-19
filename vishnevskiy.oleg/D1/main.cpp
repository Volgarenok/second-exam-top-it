#include <iostream>

char *extend(char *seq, char sym, size_t amount, size_t &s)
{
  char *tmpseq = new char[s+amount];
  if (!tmpseq)
  {
    delete[] tmpseq;
    throw;
  }
  for (size_t i = 0; i < s; i++)
  {
    tmpseq[i] = seq[i];
  }
  for (size_t i = s; i < s + amount; i++)
  {
    tmpseq[i] = sym;
  }
  delete[] seq;
  s = s+amount;
  return tmpseq;
}

int main()
{
  char sm;
  size_t s = 0, nm = 0;
  char *seq = new char[s];
  while (std::cin >> nm >> sm)
  {
    try
    {
      seq = extend(seq, sm, nm, s);
    }
    catch (...)
    {
      delete[] seq;
      return 2;
    }
  }
  if (std::cin.eof())
  {
    for (size_t i = 0; i <= s; i++)
    {
      std::cout << seq[s-i];
    }
    std::cout << "\n";
    return 0;
  }
  else
  {
    return 1;
  }
}
