#include <iostream>

namespace lachugin
{
  void expendArr(char*** arrs, size_t& oldCap)
  {
    size_t newCap = (oldCap == 0) ? 2 : oldCap * 2;
    char** newArr = new char* [newCap];
    for (size_t i = 0; i < oldCap; ++i)
    {
      newArr[i] = (*arrs)[i];
    }
    delete[] (*arrs);
    *arrs = newArr;
    oldCap = newCap;
  }

  void expendLongs(size_t** longs, size_t& oldSize)
  {
    size_t newSize = (oldSize == 0) ? 2 : oldSize * 2;
    size_t *newLengths = new size_t [newSize];
    for (size_t i = 0; i < oldSize; ++i) {
      newLengths[i] = (*longs)[i];
    }
    delete[] *longs;
    *longs = newLengths;
    oldSize = newSize;
  }
}

int main()
{
  char** arrs = nullptr;
  size_t* longs = nullptr;

  size_t n = 0;

  size_t k = 0;
  size_t cap = 0;
  while (std::cin >> n)
  {
    char* arr = new char[n];
    for (size_t i = 0; i < n; ++i)
    {
      std::cin >> arr[i];
    }
    k++;

    if (cap <= k)
    {
      size_t capCoppy = cap;
      try
      {
        lachugin::expendArr(&arrs, cap);
        lachugin::expendLongs(&longs, capCoppy);
      }
      catch (const std::bad_alloc& )
      {
        return 2;
      }
    }
  }
}
