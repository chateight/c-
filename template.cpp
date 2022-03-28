#include <iostream>

//
// simple function template
class S
{
public:
    template <typename T> 
    T foo(T value)
    {
       return value;
    }
};

//
// main routine from here
int main()
{
    S s;

    std::cout << s.foo<int>(5) << std::endl;
    std::cout << s.foo<float>(53.238f) << std::endl;

}
