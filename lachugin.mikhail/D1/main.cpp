#include <iostream>

namespace lachugin
{
  void freeArrs(char** arrs, size_t size)
  {
    for (size_t i = 0; i < size; ++i)
    {
      delete[] arrs[i];
    }
    delete[] arrs;
  }

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

  void expendLongs(size_t** longs, size_t oldSize)
  {
    size_t newSize = (oldSize == 0) ? 2 : oldSize * 2;
    size_t *newLongs = new size_t [newSize];
    for (size_t i = 0; i < oldSize; ++i) {
      newLongs[i] = (*longs)[i];
    }
    delete[] *longs;
    *longs = newLongs;
  }
}

int main()
{
  char** arrs = nullptr;
  size_t* longs = nullptr;

  size_t n = 0;
  char c = 0;

  size_t k = 0;
  size_t cap = 0;
  size_t start = 0;
  while (std::cin >> n >> c)
  {
    char* arr = new char[n];
    for (size_t i = 0; i < n; ++i)
    {
      arr[i] = c;
    }
    if (cap <= k)
    {
      size_t capCoppy = cap;
      try
      {
        lachugin::expendArr(&arrs, cap);
        lachugin::expendLongs(&longs, capCoppy);
      }
      catch (const std::bad_alloc&)
      {
        lachugin::freeArrs(arrs, k);
        delete[] arr;
        delete[] longs;
        std::cout << "\n";
        return 2;
      }
    }
    k++;
    longs[start] = n;
    arrs[start++] = arr;
  }

  if (!std::cin.eof() && !std::cin)
  {
    std::cerr << "Error: invalid input\n";
    lachugin::freeArrs(arrs, k);
    delete[] longs;
    return 1;
  }

  for (size_t i = k; i > 0; --i)
  {
    size_t idx = i - 1;
    for (size_t j = longs[idx]; j > 0; --j)
    {
      std::cout << arrs[idx][j - 1];
    }
  }
  lachugin::freeArrs(arrs, k);
  delete[] longs;
}
