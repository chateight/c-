#include <iostream>

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
}