#include <iostream>

namespace rizatdinov
{
  void extend(char ** str_array, size_t k, size_t d);
  void extend(unsigned ** num_array, size_t k, size_t d);
  void handleInput(unsigned ** num_array, char ** str_array, size_t & size);
}

int main()
{
  unsigned * num_array = nullptr;
  char * str_array = nullptr;
  size_t size = 0;

  try {
    rizatdinov::handleInput(&num_array, &str_array, size);
  } catch(...) {
    std::cout << "Error: 1\n";

    delete[] num_array;
    delete[] str_array;

    return 1;
  }

  for (size_t i = 0; i < size; ++i) {
    std::cout << num_array[i] << ' ' << str_array[i] << '\n';
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

void rizatdinov::handleInput(unsigned ** num_array, char ** str_array, size_t & size)
{
  size_t sizeD = 2;
  char * str_data = new char[sizeD];
  unsigned * num_data = new unsigned[sizeD];

  size_t i = 0;
  for (; std::cin >> num_data[i] >> str_data[i] && !std::cin.eof(); ++i) {
    if (i + 1 == sizeD) {
      rizatdinov::extend(&str_data, sizeD, sizeD + sizeD*2);
      rizatdinov::extend(&num_data, sizeD, sizeD + sizeD*2);
      sizeD += sizeD*2;
    }
  }
  rizatdinov::extend(&str_data, sizeD, i);
  rizatdinov::extend(&num_data, sizeD, i);

  size = i;
  *str_array = str_data;
  *num_array = num_data;
}
