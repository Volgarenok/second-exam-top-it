#include <iostream>

void extend();

int main() {
  unsigned int size = 0;
  unsigned int num = 0;
  char bukv;
  char* h = char new[10];
  unsigned int cap = 10;
  int index = 0;
  while (true) {
    std::cin >> num;
    std::cin >> bukv;
    size += num;
    if (std::cin.fail()) {
      std::cerr << "Invalid input" << '\n';
      return 1;
    }
    if (cap < size) {
      h = extand(h, cap);
    }
    for (int i = 0; i < num; i++) {
      h[index] = bukv;
      index++;
    }
  }
  int index2 = size;
  for (int i = 0; i < size; i++){
    std::cout << h[index2];
    index2--;
  }
}

char* extand(char *data, unsigned int cap) {
  unsigned int nCap = cap * 2; 
  try {
  char* newData = new char[nCap];
  for (int i = 0; i < Cap; i++) {
    newData[i] = data[i];
  }
  delete[] data;
  return newData;
   } catch(...) {
    delete [] data;
    std::cerr << "нету места для массива" << '\n';
    return 2;
  }
}