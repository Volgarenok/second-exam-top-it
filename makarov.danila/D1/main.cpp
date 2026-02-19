#include <iostream>

void extend();

int main() {
  unsigned int size = 0;
  unsigned int num = 0;
  char bukv;
  char h = char new[10];
  while (true) {
    std::cin >> num;
    std::cin >> bukv;
    size += num;
    if (std::cin.fail()) {
      std::cerr << "Invalid input" << '\n';
      return 1;
    }
    char h = char new[size]
  }
  return 0;
}

void extand(int cap) {
  int nCap = cap * 2; 
  int* newData = new int[nCap];
  for (int i = 0; i < size; i++) {
    newData[i] = data[i];
  }
  delete[] data;
  data = newData;
  capacity = newCapacity;
}