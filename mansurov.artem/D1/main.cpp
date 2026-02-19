#include <iostream>
namespace mansurov{
    size_t* extend(size_t** numbers, size_t new_num);
}
int main(){
    using namespace mansurov;
    size_t* numbers = nullptr;
    char* symbols = nullptr;
    size_t count = 0;
    try{
        while(std::cin){
            size_t tmp_num = 0;
            std::cin >> tmp_num;
            if(!std::cin){
                if(std::cin.eof()){
                    std::cout << "missing symbol" << "\n";
                }
            }
            char tmp_char = ' ';
            std::cin >> tmp_char;
            if()
        }
    }
}