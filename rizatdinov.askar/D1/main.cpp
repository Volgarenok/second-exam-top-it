#include <iostream>

namespace rizatdinov
{
  void extend(char ** str_array, size_t k, size_t d);
  void extend(unsigned ** num_array, size_t k, size_t d);
}

int main()
{
  unsigned * num_array = nullptr;
  char * str_array = nullptr;
  size_t size_array = 3;

  try {
    num_array = new unsigned[3]{ 2, 0, 3 };
    str_array = new char[3]{ 'a', 'b', 'c' };

    rizatdinov::extend(&num_array, 3, 2);
    for (size_t i = 0; i < 2; ++i) {
      std::cout << num_array[i] << '\n';
    }
    rizatdinov::extend(&str_array, 3, 2);
    for (size_t i = 0; i < 2; ++i) {
      std::cout << str_array[i] << '\n';
    }
  } catch(...) {
    std::cout << "Error: 1\n";
    delete[] num_array;
    delete[] str_array;
    return 1;
  }

  delete[] num_array;
  delete[] str_array;

  return 0;
}

void rizatdinov::extend(char ** str_array, size_t k, size_t d)
{
  char * new_array = new char[d];
  for (size_t i = 0; i < std::min(k, d); ++i) {
    new_array[i] = (*str_array)[i];
  }
  delete[] *str_array;
  *str_array = new_array;
}

void rizatdinov::extend(unsigned ** num_array, size_t k, size_t d)
{
  unsigned * new_array = new unsigned[d];
  for (size_t i = 0; i < std::min(k, d); ++i) {
    new_array[i] = (*num_array)[i];
  }
  delete[] *num_array;
  *num_array = new_array;
}
