#include <iostream>
#include <memory>
#include <utility>
#include <typeinfo>
#include <cxxabi.h>


// basic operator overload
class Float{
    float val;

public:
    Float(float val) : val(val){}

    Float operator+(const Float& rf) const;
    Float operator-(const Float& rf) const;

    Float operator+() const;        // return the sign of the variable
    Float operator-() const;

    void show() const;
};

Float Float::operator+(const Float& rf) const{
    return Float{val + rf.val};
}

Float Float::operator-(const Float& rf) const{
    return Float{val - rf.val};
}

Float Float::operator+() const{
    return *this;
}

Float Float::operator-() const{
    return Float{-val};
}

void Float::show() const{
    std::cout << val << std::endl;
}

//
// std::unique_ptr(automatically release the acquired resources by the destructor)
class stdrd{
    std::string str = "initialized to \"stdrd string\"";

public:
    void show(){
        std::cout << str << std::endl;
    }

    stdrd(){
        std::cout << " constructor was called" << std::endl;
    }

    ~stdrd(){
        std::cout << " destructor was called" << std::endl;
    }
};

std::unique_ptr<stdrd> allocate(){
    std::cout << " allocated" << std::endl;
    std::unique_ptr<stdrd> ptr{new stdrd{}};

    return std::move(ptr);                      // "ptr" owner is changed, "ptr" return extends the lifetime of "ptr"
}


int main(){
    std::cout << "----- basic operator override(floating plus & minus) -----" << std::endl;
    Float x = 7.34f;
    Float y = 5.17f;

    auto v = x + y;
    v.show();

    auto w = x - y;
    w.show();

    auto p = +x;
    p.show();

    auto q = -x;
    q.show();

    {
        std::cout << "----- std::unique_ptr -----" << std::endl;
        std::unique_ptr<stdrd> ptr;
        std::cout << "before func call" << std::endl;
        ptr = allocate();
        std::cout << "after func call" << std::endl;

        ptr -> show();                              // call by pointer

        stdrd& ptr_r = *ptr;
        ptr_r.show();                               // call by reference

        const std::type_info& id = typeid(ptr);     // to get class name of the "ptr" instance
        int stat;
        char *name = abi::__cxa_demangle(id.name(),0,0,&stat);
        if(stat==0) {
            std::cout << name << std::endl;         
        }
    
    }
    std::cout << "after the scope" << std::endl;
}