#include <iostream>

//
// "protected" : access protection ( same as other languages i.e. Java & C#)
class base{

    int var_p{30};  // private variable

protected:          // "proteted" is also applicable to functions
    int var{10};

public:
    base(){}
    explicit base(int i);
};

base::base(int i){
    std::cout << " instantiated : " << i << std::endl;
}

class inherit : public base{
public:
    explicit inherit(int i) : base{i} {}         // make inherit class constructor calling the base class constructor
    void show();
};

void inherit::show(){
//    std::cout << " access from inherit class : " << var_p << std::endl;       // error due to access to the private variable
    std::cout << " access from inherit class : " << var << std::endl;
}

class inherit_p : private base{         // "inherit_p" could not be inherited anymore"
public:
    void show();
};

void inherit_p::show(){
    std::cout << " access from inherit_p class : " << var << std::endl;     // accessible only public function
}

//
// derived class can make reference or pointer of th base class
class base_r{

public:
    void base_show();
};

void base_r::base_show(){
    std::cout << "base_show" << std::endl;
}

class inherit_r : public base_r{

public:
    void inherit_show();
};

void inherit_r::inherit_show(){
    std::cout << "inerit_show" << std::endl;
}

//
// main routine
int main(){
    std::cout << "----- protected access protection -----" << std::endl;
    inherit inh(35);
    inh.show();

    inherit_p inh_p;
    inh_p.show();

    std::cout << "----- inherit class can make base class ref & pointer -----" << std::endl;

    base_r base;

    inherit_r inh_r;

    inh_r.base_show();
    inh_r.inherit_show();

    base_r* ptr= &inh_r;            // if you change the order of this two lines, it causes error, why?
    base_r& base_r = inh_r;

    base_r.base_show();
    ptr -> base_show();

}
