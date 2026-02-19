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
        std::cin >> symb;
        if(std::cin.fail()){
            print(arr, s);
            return 1;
        }
        for(unsigned int i = 0; i < count; i++){
            if(s == cap){
                size_t new_cap = (cap == 0) ? 16 : cap * 2;
                char* new_arr = new (std::nothrow) char[new_cap];
                if(new_arr == nullptr){
                    print(arr, s);
                    return 2;
                }
                for(size_t k = 0; k < s; k++){
                    new_arr[k] = arr[k];
                }
                delete[] arr;
                arr = new_arr;
                cap = new_cap;
            }
            arr[s++] = symb;
        }
    }
    print(arr, s);
    return 0;
}
}
int main() {
}