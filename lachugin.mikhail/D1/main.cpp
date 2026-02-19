#include <iostream>

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
