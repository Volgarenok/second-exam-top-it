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
    virtual ~IProcessor() = default;

  protected:
    virtual void doAddPair(unsigned int num, char ch) = 0;
    virtual void doPrint();
  };
}
int main()
{
}
