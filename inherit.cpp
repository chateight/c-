#include <iostream>

//
// "protected" : access protection ( same as other languages i.e. Java C#)
class base{

    int var_p{30};  // private variable

protected:          // "proteted" is applicable to functions also
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
    explicit inherit(int i) : base{i} {}         // make constructor initializing the base class
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
// main routine
int main(){
    std::cout << "----- protected access protection -----" << std::endl;
    inherit inh(35);
    inh.show();

    inherit_p inh_p;
    inh_p.show();

}
