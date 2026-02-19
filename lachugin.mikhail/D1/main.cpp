#include <iostream>

namespace lachugin
{
  void expendArr(char*** arrs, size_t& oldCap)
  {
    size_t newCap = (oldCap == 0) ? 2 : oldCap * 2;
    char** newArr = new char* [newCap];
    for (size_t i = 0; i < oldCap; ++i) {
      newArr[i] = (*arrs)[i];
    }
    delete[] (*arrs);
    *arrs = newArr;
    oldCap = newCap;
  }
}

int main()
{
  size_t n = 0;
  char k = 0;

  char** arrs = nullptr;
  size_t* longs = nullptr;

  while (std::cin >> n)
  {
    char* arr = new char[n];
    for (size_t i = 0; i < n; ++i)
    {
      std::cin >> arr[i];
    }

  }
}
