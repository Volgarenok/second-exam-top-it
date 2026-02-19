#include <iostream>

namespace karpenkov{
  char * expand (char * arr, size_t len, size_t newLen){
    char * str = new char[len + newLen];
    for (size_t i = 0; i < len; i++){
      str[i] = arr[i];
    }
    delete[] arr;
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
    delete[] arr;
    return str;
  }
}

int main()
{
  size_t size = 0, cap = 10, number = 0;
  char letter;
  char * r = new char[cap];
  while (std::cin >> number){
    if (!(std::cin >> letter)){
      std::cerr << "input error" << '\n';
      delete [] r;
      return 1;
    }
    if (size + number >= cap){
      try{
        r = karpenkov::expand(r, size, number);
        cap += number;
        r = karpenkov::addNewLetters(r, size, number, letter);
      }
      catch(std::bad_alloc){
        std::cerr << "bad_alloc" << '\n';
         delete [] r;
        return 2;
      }
    }
    else{
      r = karpenkov::addNewLetters(r, size, number, letter);
    }
  }
  if (size < cap){
    try{
      r = karpenkov::cut(r, size);
    }
    catch(std::bad_alloc){
      std::cerr << "bad_alloc" << '\n';
      delete [] r;
    }
  }
  karpenkov::reverseLetters(r, size);
}