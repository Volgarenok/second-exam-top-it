#include <iostream>

int main(int argc, char* argv[])
{
  bool reverse = false;

  if (argc == 1)
  {
    std::cout << "Popa\n";
  }
  else if (argc == 2)
  {
    const char* arg = argv[1];
    if (arg[0] == 'r' &&
        arg[1] == 'e' &&
        arg[2] == 'v' &&
        arg[3] == 'e' &&
        arg[4] == 'r' &&
        arg[5] == 's' &&
        arg[6] == 'e' &&
        arg[7] == '\0')
    {
      std::cout << "Popa 2\n";
      reverse = true;
    }
    else
    {
      std::cerr << "invalid arguments\n";
      return 1;
    }
  }
  else
  {
    std::cerr << "invalid arguments\n";
    return 1;
  }

  return 0;
}
