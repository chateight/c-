#include <iostream>
#include <string.h>

class basic_class{
    public: struct production{
        int qty;
        int invent;
    };
    production metal = {
        24,
        12,
    };
    production ret_metal(){
        return metal;
    }
};

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

    // struct
    struct product{
        int id;
        int price;
        int stock;
    };
    product note = {        // initialize "note" having product structure
            101,
            200,
            32,
    };
    product* s_ptr = &note; // pointer to the note struct
    std::cout << s_ptr -> id << std::endl;  // access by pointer
    note.stock --;                          // access by member
    std::cout << s_ptr -> stock << std::endl;

    // union    *where do I use it?
    union product_u{
        int pro_a;
        int pro_b;
        int pro_c;
    };
    product_u u;
    std::cout << &u.pro_a << std::endl;     // pro_a, pro_b and pro_c denote same address
    std::cout << &u.pro_b << std::endl;

    // enumeration
    enum class product_l : int{             // enumeration varialble type definition
        n_pro_a,
        n_pro_b,
        n_pro_c = 10,
        n_pro_d,
    };
    product_l num = product_l::n_pro_c;
    std::cout << static_cast<int>(num) << std::endl;        // implicit type conversion does not work

    // referencce
    int i = 0;
    int& rj = i;        // rj and i denote same address
    rj = i;

    rj = 42;
    std::cout << i << std::endl;
    
    // const
    const int ci = 32;
    const int& cr = ci;     // const reference should be defined as const
    std::cout << cr << std::endl;

    // basic class usage
    basic_class bc;
    basic_class::production prd = bc.ret_metal();           // actual data is conceiled in the class
    std::cout <<  " metal return = " << prd.qty << std::endl;
    //std::cout <<  " metal return = " << metal.qty << std::endl;   // this does not work
}

