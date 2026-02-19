#include <iostream>

void extend(char *seq, char sym, size_t amount, size_t s)
{
  char *tmpseq = new char[s+amount];
  for (size_t i = 0; i < s; i++)
  {
    tmpseq[i] = seq[i];
  }
  for (size_t i = s; i < s + amount; i++)
  {
    tmpseq[i] = sym;
  }
  char *t = seq;
  seq = tmpseq;
  tmpseq = t;
  delete[] t;
}

int main()
{
  return 0;
}
