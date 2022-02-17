#include <iostream>

#include <string.h>

int main(){

    // basic pointer function
    int aa = 7;
    int* ptra = &aa;
    *ptra = 8;
    std::cout << " aa = " << aa << std::endl;

    // pointer of the pointer
    int a = 10;
    int b = 20;
    const int* ptr = &a;    // if you delete const, it causes compile error
    ptr = &b;               // const pointer disables changes of the pointer denoted variable, in this case int a & b.
    const int** pptr = &ptr;
    std::cout << ptr << std::endl;
    std::cout << pptr << std::endl;
    std::cout << &pptr << std::endl;

    // null pointer
    ptr = nullptr;          // null pointer set to 0x0
    std::cout << ptr << std::endl; 

    // cast
    std::cout << static_cast<float>(a)/3 << std::endl;

    // char and string
    char hello[] = "hello";
    std::cout << "size of string hello : " <<sizeof(hello) << std::endl;        // null was added to the string hello[]
    char array[5] = {'t','o','m','y'};
    array[4] = '\0';                                // null expression is '\0', null is added implicitly. you can not use nullptr instead of '\0'
    std::cout << hello << "," << array << std::endl;

    // std::string is more convenient in c++
    std::string str = "hello from";
    str += " Jhon";                                 // combine strings
    std::cout << str << " ; size of str : " << str.size() << std::endl;  // size of string has no null space

    // range based for
    std::string sstr = "alpha beta";
    for (char ele : sstr){
        std::cout << ele;
    }
    std::cout << std::endl;
}