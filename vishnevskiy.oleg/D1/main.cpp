#include <iostream>

int main()
{
  char sm;
  size_t s = 0, nm = 0;
  char *seq = new char[s];
  while (std::cin >> nm >> sm)
  {
    char *tmpseq = nullptr;
    try
    {
      tmpseq = new char[(s+nm)];
    }
    catch (...)
    {
      delete[] tmpseq;
      delete[] seq;
      return 2;
    }
    for (size_t i = 0; i < s; i++)
    {
      tmpseq[i] = seq[i];
    }
    for (size_t i = s; i < s + nm; i++)
    {
      tmpseq[i] = sm;
    }
    delete[] seq;
    seq = tmpseq;
    tmpseq = nullptr;
    s = s+nm;

  }
  if (std::cin.eof())
  {
    for (size_t i = 0; i <= s; i++)
    {
      if (i <= s){
        std::cout << seq[s-i];
      }
    }
    std::cout << "\n";
    return 0;
  }
  else
  {
    return 1;
  }
}
