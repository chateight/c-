#include <iostream>

int main(){
    int i = 0;
    i *= 2 + 4;         // compound assignment operater (+ has higher priority than * & =)
    std::cout << i << std::endl;
    i %= 3;
    std::cout << i << std::endl;
    return(0);
}