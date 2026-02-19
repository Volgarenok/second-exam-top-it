#include <iostream>

namespace krivoshapov
{
  class IProcessor
  {
  public:
    void addPair(unsigned int num, char ch)
    {
      doAddPair(num, ch);
    }
    void print()
    {
      doPrint();
    }
  }
}
int main()
{
}
