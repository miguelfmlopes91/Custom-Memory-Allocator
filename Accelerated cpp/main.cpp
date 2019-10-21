#include <iostream>

#include "str.h"

int main(){
    
    Str str("lol");
//    Vec<int> vec(10);
//    for (int i = 0; i< vec.size(); ++i) {
//        std::cout << vec[i] << std::endl;
//    }
    Str temp = str + "ajaa";
    std::cout<<str << std::endl;
    return 0;
}
