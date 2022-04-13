#include <iostream>
#include <typeinfo>

//
// same delta expression has defferent type
auto delta_a = [](std::string str){
    std::cout << str << std::endl;
};

auto delta_b = [](std::string str){
    std::cout << str << std::endl;
};

//
// check the type of the received reference for the base class
class base{

public:
    virtual ~base() {}      // destructor definition as virtual is a key to keep polymorphic

};

class inherit : public base{

};

void rec(const base& ins){
    if (typeid(ins) == typeid(inherit)){
        std::cout << "ref has a same type of the inherit class" << std::endl;
    }
    else{
        std::cout << "ref does not have a same type of the inherit class" << std::endl;
    }
}

//
// down cast using static_cast
class base_s{

public:

virtual ~base_s(){};

const char* show_name()
    const {return "base_s";}

};

class inhe_s : public base_s{

public:

const char* show_name()
    const {return "inhe_s";}

};


//
// main method from here
int main(){

    std::cout << std::endl;
    std::cout << "----- does the same delta expressions have same type? -----" << std::endl;
    
    if ( typeid(delta_a) == typeid(delta_b)){
        std::cout << "same delta expression has same type" << std::endl;
    }
    else{
        std::cout << "same delta expression has defferent type" << std::endl;

    }

    std::cout << std::endl;
    std::cout << "----- check the type of the received reference -----" << std::endl;

    base ins;
    inherit ins_i;

    rec(ins);
    rec(ins_i);

    std::cout << std::endl;
    std::cout << "----- down cast using static_cast -----" << std::endl;

    inhe_s sc;
    base_s* pb = &sc;
    inhe_s* pi = static_cast<inhe_s*>(pb);          // cast to the inhe_s
    std::cout << pi->show_name() << std::endl;

    std::cout << std::endl;
    std::cout << "----- down cast using dynamic_cast -----" << std::endl;

    base_s rb = sc;

    try{
        inhe_s pd = dynamic_cast<inhe_s&>(rb);      // pd is not a reference
    }
    catch(std::bad_cast&){
        std::cout << "fail to cast" << std::endl;
    }

}