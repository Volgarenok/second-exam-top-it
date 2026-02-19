#include <iostream>

int main(int argc, char* argv[]) {
  bool rev = false;
  if (argc == 1) {
    rev = false;
  } else if (argc == 2) {
    if (argv[1][0] == 'r' && argv[1][1] == 'e' && argv[1][2] == 'v'
      && argv[1][3] == 'e' && argv[1][4] == 'r' && argv[1][5] == 's'
      && argv[1][6] == 'e' && argv[1][7] == '\0') {
      rev = true;
    } else {
      std::cerr << "Input error\n";
      std::cout << '\n';
      return 1;
    }
  } else {
    std::cerr << "Input error\n";
    std::cout << '\n';
    return 1;
  }
  char* a = nullptr;
  size_t size = 0;
  size_t cap = 0;
  char ch;
  while (std::cin >> ch) {
    if (size + 1 > cap) {
      size_t newCap;
      if (cap == 0) {
        newCap = 1;
      } else {
        newCap = cap;
      }
      while (newCap < size + 1) {
        newCap *= 2;
      }
      char* b = nullptr;
      try {
        b = new char[newCap];
      } catch (const std::bad_alloc&) {
        std::cout << '\n';
        delete[] a;
        return 2;
      }
      for (size_t i = 0; i < size; ++i){
        b[i] = a[i];
      }
      delete[] a;
      a = b;
      cap = newCap;
    }
    a[size++] = ch;
  }
  if (!std::cin.eof()) {
    std::cerr << "Input error\n";
    std::cout << '\n';
    delete[] a;
    return 1;
  }
  if (size == 0) {
    std::cout << '\n';
    delete[] a;
    return 0;
  }
  if (!rev) {
    size_t i = 0;
    while (i < size) {
      char c = a[i];
      size_t j = i + 1;
      while (j < size && a[j] == c) {
        ++j;
      }
      std::cout << (j - i) << ' ' << c << '\n';
      i = j;
    }
  } else {
    size_t k = size;
    while (k > 0) {
      char c = a[k - 1];
      size_t j = k - 1;
      while (j > 0 && a[j - 1] == c) --j;
      std::cout << (k - j) << ' ' << c << '\n';
      k = j;
    }
  }
  delete[] a;
}
