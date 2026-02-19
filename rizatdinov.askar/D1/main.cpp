#include <iostream>

namespace rizatdinov
{
  void extend(char ** str_array, size_t k, size_t d);
  void extend(unsigned ** num_array, size_t k, size_t d);
  size_t handleInput(unsigned ** num_array, char ** str_array);
}

int main()
{
  unsigned * num_array = nullptr;
  char * str_array = nullptr;
  size_t size = 0;

  try {
    size = rizatdinov::handleInput(&num_array, &str_array);
  } catch(...) {
    std::cerr << "Error: 2\n";

    delete[] num_array;
    delete[] str_array;

    return 2;
  }

  if (!size) {
    std::cerr << "Error: 1\n";
    return 1;
  }

  for (size_t i = 1; i <= size; ++i) {
    unsigned count = num_array[size - i];
    for (size_t j = 0; j < count; ++j) {
      std::cout << str_array[size - i];
    }
  }
  std::cout << '\n';

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

size_t rizatdinov::handleInput(unsigned ** num_array, char ** str_array)
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
  if ((std::cin.bad() || std::cin.fail()) && !std::cin.eof()) {
    delete[] num_data;
    delete[] str_data;

    return 0;
  }

  rizatdinov::extend(&str_data, sizeD, i);
  rizatdinov::extend(&num_data, sizeD, i);

  *str_array = str_data;
  *num_array = num_data;

  return i;
}
