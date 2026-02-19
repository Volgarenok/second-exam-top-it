#include <iostream>
#include <new>

namespace emushintsev{

void print(char* arr, size_t s){
    if (arr != nullptr && s > 0){
        for (size_t i = s; i > 0; i--){
            std::cout << arr[i - 1];
        }
    }
    std::cout << std::endl;
    delete[] arr;
}

int solve(){
    size_t s = 0;
    size_t cap = 0;
    char* arr = nullptr;
    unsigned int count;
    char symb;
    while (true){
        std::cin >> count;
        if(std::cin.fail()){
            if(std::cin.eof()){
                break;
            }
            print(arr, s);
            return 1;
        }
    }
}

int main() {

}