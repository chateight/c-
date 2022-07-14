#include <iostream>

using my_func = int (*)(int,int);


int mul(int a, int b)
{
    return a*b;
}

void calc(int a, int b, my_func p)
{        
    std::cout << (*p)(a, b) << std::endl;
}

int main(){
    my_func p = &mul;       // "&mul" is equivalent to "mul"
    calc(10, 10, p);
    return 0;
}
