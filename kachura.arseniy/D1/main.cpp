#include <iostream>

int main()
{
  unsigned amount, old_amount;
  char symbol;
  char* buffer = new char[1];
  old_amount = 0;
  while(std::cin >> amount >> symbol)
  {
    amount = amount + old_amount;
    std::cout << "new amount: " << amount << '\n' << "old amount: " << old_amount << "\n";
    char* result = new char[amount];
    if(old_amount != 0)
    {
      for(int u = 0; u < amount; u++)
      {
        if(u < old_amount)
        {
          result[u] = buffer[u];
        }
        else
        {
          result[u] = symbol;
        }
      }
      for(size_t i = 0; i < amount; i++)
      {
        std::cout << result[i];
      }
      std::cout << '\n';
      delete[] buffer;
      buffer = nullptr;
      char* buffer = new char[amount];
      std::cout << "fuck";
    }
    else
    {
      std::cout << "first symbols\n";
      for(size_t u = 0; u < amount; u++)
      {
        result[u] = symbol;
      }
      std::cout << "created buffer\n";
      char* buffer = new char[amount];
    }
    old_amount = amount;
    for(int u = 0; u < old_amount; u++)
    {
      std::cout << "copy";
      buffer[u] = result[u];
    }
    for(size_t i = 0; i < amount; i++)
    {
      std::cout << result[i];
    }
    std::cout << '\n';
    for(size_t i = 0; i < amount; i++)
    {
      std::cout << buffer[i];
    }
    std::cout << '\n';
    delete[] result;
    result = nullptr;
  }
}
