#include <iostream>

namespace karpenkov{
  char * expand (char * arr, size_t len, size_t newLen){
    char * str = new char[newLen];
    for (size_t i = 0; i < len; i++){
      str[i] = arr[i];
    }
    return str;
  }
  char * addNewLetters(char * arr, size_t& size, size_t count, char letter){
    for (size_t i = 0; i < count; i++){
      arr[size++] = letter;
    }
    return arr;
  }
  void reverseLetters(char * arr, size_t size){
    for(size_t i = size; i > 0; i--){
      std::cout << arr[i - 1];
    }
  }
  char * cut (char * arr, size_t size){
    char * str = new char[size];
    for (size_t i = 0; i < size; i++){
      str[i] = arr[i];
    }
    return str;
  }
}

int main()
{
  size_t size = 0, cap = 10, number = 0;
  char letter;
  char * r = new char[cap];
  bool inputError = false;
  while (std::cin >> number){
    if (!(std::cin >> letter)){
      inputError = true;
      break;
    }
    if (size + number > cap){
      size_t newCap = cap + number + 10;
      try{
        char * newArr = karpenkov::expand(r, size, newCap);
        cap = newCap;
      }
      catch(...){
        std::cerr << "bad_alloc" << '\n';
        delete [] r;
        std::cout << '\n';
        return 2;
      }
      delete [] r;
      r = newArr;
    }
    r = karpenkov::addNewLetters(r, size, number, letter);
  }
  if (inputError){
    karpenkov::reverseLetters(r, size);
    return 1;
  }
  if (std::cin.fail() && !std::cin.eof()){
    std::cerr << "input error" << '\n';
    delete [] r;
    std::cout << '\n';
    return 1;
  }
  if (size == 0){
    delete [] r;
    std::cout << '\n';
    return 0;
  }
  if (size < cap){
    try{
      char * newArr = karpenkov::cut(r, size);
    }
    catch(...){
      std::cerr << "bad_alloc " << '\n';
      delete [] r;
      std::cout << '\n';
      return 2;
    }
    delete [] r;
    r = newArr;
  }
  karpenkov::reverseLetters(r, size);
  if (inputError){
    std::cerr << "input error" << '\n';
    std::cout << '\n';
    return 1;
  }
  return 0;
}
