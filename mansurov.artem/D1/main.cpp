#include <iostream>
#include <typeinfo>
#include <string>

namespace mansurov{
  void extend(size_t** numbers, size_t count, size_t new_num);
  void extend(char** chars, size_t count, char new_char);
  char* in_string(const size_t* numbers, const char* symbols, size_t n, size_t& count);
}

int main(){
  using namespace mansurov;
  size_t* numbers = nullptr;
  char* symbols = nullptr;
  size_t count = 0;
  
  try{
    while(std::cin){
      int tmp_num = 0;
      std::cin >> tmp_num;
      
      if(!std::cin){
        if(std::cin.eof()){
          break;
        }
        std::cerr << "input error" << "\n";
        return 1;
      }
      
      if(tmp_num < 0){
        std::cerr << "negative numbers" << "\n";
        return 1;
      }
      
      char tmp_char = ' ';
      std::cin >> tmp_char;
      
      if(!std::cin){
        if(std::cin.eof()){
          break;
        }
        std::cerr << "input error" << "\n";
        return 1;
      }
      
      extend(&numbers, count, static_cast<size_t>(tmp_num));
      extend(&symbols, count, tmp_char);
      count++;
    }
    
    size_t count_chars = 0;
    char* str = in_string(numbers, symbols, count, count_chars);
    
    for(size_t i = 0; i < count_chars; i++){
      std::cout << str[count_chars - 1 - i];
    }
    std::cout << "\n";
    
    delete[] str;
    delete[] numbers;
    delete[] symbols;
  }
  catch(const std::bad_alloc & e){
    std::cerr << "bad alloc: " << e.what() << std::endl;
    delete[] numbers;
    delete[] symbols;
    return 2;
  }
  
  return 0;
}

void mansurov::extend(size_t** num, size_t n, size_t count)
{
  size_t* new_num = new size_t[n + 1];
  for (size_t i = 0; i < n; ++i) {
    new_num[i] = (*num)[i];
  }
  new_num[n] = count;
  delete[] (*num);
  *num = new_num;
}

void mansurov::extend(char** num, size_t n, char count)
{
  char* new_num = new char[n + 1];
  for (size_t i = 0; i < n; ++i) {
    new_num[i] = (*num)[i];
  }
  new_num[n] = count;
  delete[] (*num);
  *num = new_num;
}

char* mansurov::in_string(const size_t* numbers, const char* symbols, size_t n, size_t& count){
  count = 0;
  for(size_t i = 0; i < n; i++){
    count += numbers[i];
  }
  
  char* new_str = new char[count + 1];
  
  size_t c = 0;
  for(size_t i = 0; i < n; i++){
    for(size_t k = 0; k < numbers[i]; k++){
      new_str[c] = symbols[i];
      c++;
    }
  }
  
  new_str[count] = '\0';
  
  return new_str;
}