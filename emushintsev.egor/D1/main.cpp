#include <iostream>
#include <new>

void print(char* arr, size_t s){
    if (arr != nullptr && s > 0){
        for (size_t i = s; i > 0; i--){
            std::cout << arr[i - 1];
        }
    }
}

int main() {

}