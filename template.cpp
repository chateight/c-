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
// class template
template <typename CT>
class ct{

public:
CT val;

void ct_f();
};

template <typename CT>
void ct<CT>::ct_f(){
    std::cout << val << std::endl;
}

//
// use virtual function in a class template
class ctv{

public:
    virtual void show(float fl){
        std::cout << "base : " << fl << std::endl;
    }

};

template <typename T>
class d_ctv : public ctv{

public:
    void show(T vbl) override{
        std::cout << "override : " << vbl << std::endl;
    }

};

//
// main routine from here
int main()
{
    S s;

    std::cout << "----- template function -----" << std::endl;
    std::cout << " int : "<< s.foo<int>(5) << std::endl;
    std::cout << " float : " << s.foo<float>(53.238f) << std::endl;
    std::cout << " char : " << s.foo<char>('d') << std::endl;
    std::cout << " string : " << s.foo<std::string>("hello") << std::endl;

    std::cout << std::endl;
    std::cout << "----- template class -----" <<std::endl;
    ct<float> tc{52.3f};
    tc.ct_f();

    ct<std::string> tc_s{"bigger"};
    tc_s.ct_f();

    std::cout << std::endl;
    std::cout << "----- using virtual function in a template class -----" <<std::endl;
    d_ctv<float> vin;
    vin.show(28);
    vin.ctv::show(21);
    static_cast<ctv&>(vin).show(27);        // call via virtual function( result is same as above )

}
