#include <iostream>

int main()
{
  unsigned amount;
  char symbol;
  while(std::cin >> amount >> symbol)
  {

    char* array = new char[amount];
    for(size_t i = 0; i < amount; i++)
    {
      array[i] = symbol;
    }
    for(size_t i = 0; i < amount; i++)
    {
      std::cout << array[i];
    }
    std::cout << '\n';
    delete[] array;
    array = nullptr;
  }
}
