#include <iostream>

int main(int argc, char *argv[])
{
  bool reverse = false;

  if (argc > 2)
  {
    std::cerr << "Invalid arguments" << '\n';
    return 1;
  }

  if (argc == 2)
  {
    if (std::string(argv[1]) == "reverse")
      reverse = true;
    else
    {
      std::cerr << "Invalid arguments" << '\n';
      return 1;
    }
  }
}