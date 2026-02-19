#include <iostream>

char* extend(char *data, unsigned int &cap);

int main() {
  unsigned int size = 0;
  unsigned int num = 0;
  char bukv;
  char* h = new char[10];
  unsigned int cap = 10;
  int index = 0;
  while (true) {
    std::cin >> num;
    std::cin >> bukv;
    if (std::cin.fail()) { 
      std::cerr << "Invalid input" << '\n';
      delete[] h;
      return 1;
    }
    size += num;
    if (cap < size) {
      h = extend(h, cap);
      if (h == nullptr) {
        std::cerr << "Ошибка расширения массива" << '\n';
        return 2;
      }
    }
    for (int i = 0; i < num; i++) {
      h[index] = bukv;
      index++;
    }
  }
  int index2 = size - 1;
  for (int i = 0; i < size; i++) {
    std::cout << h[index2];
    index2--;
  }
  std::cout << '\n';
  delete[] h;
}

char* extend(char *data, unsigned int &cap) {
  unsigned int nCap = cap * 2;
  try {
    char* newData = new char[nCap];
    for (int i = 0; i < cap; i++) {
      newData[i] = data[i];
    }
    delete[] data;
    cap = nCap;
    return newData;
  } catch(...) {
    return nullptr;
    delete [] data;
  }
}
