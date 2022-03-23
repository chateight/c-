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
    virtual void base_show();
    virtual ~base_r(){ std::cout << "base_r destructor was called" << std::endl; }                         // virtual distructor is used for inherit class resource release, however it consumne many resource
};                                              // inherit class empty destructor is automatically defined by compiler

void base_r::base_show(){
    std::cout << "base_show()" << std::endl;
}

class inherit_r : public base_r{                

public:
    void inherit_show();
    void base_show() override;
    ~inherit_r(){
        std::cout << " inherit_r destructor was called" << std::endl;
    }
};

void inherit_r::inherit_show(){
    std::cout << "inerit_show()" << std::endl;
}

void inherit_r::base_show(){
    std::cout << "inherit base_show()" << std::endl;
}

base_r* allocate(){
    return new inherit_r{};
}

//
// multiple inheritance (multiple inheritance can be used, but it's an exception due to lack of readbility)
class m_base1{

public:
    void show(){
        std::cout << "base1 function was called" << std::endl;
    }

    void log(){
        std::cout << "log info" << std::endl;
    }

};

class m_base2{

public:
    void show(){
        std::cout << "base2 function was called" << std::endl;
    }

};

class m_inherit: public m_base1, public m_base2{

};

//
// virtual base class
class v_base{

public:
    explicit v_base(int val){
        std::cout << "instantiated @ " << val << std::endl;         // "val" is set to the instanciated class number (1,2 : first layer, 3 : final layer)
    }

    void method_vb(){
        std::cout << "base_class:" << this << std::endl;
    }

};

class v_inherit1: virtual public v_base{        // virtual inheritance 

public:
    v_inherit1() : v_base{1} {}

    void method_inherit1(){
        std::cout << "inherit1_class:" << this << std::endl;
    }

};

class v_inherit2: virtual public v_base{

public:
    v_inherit2() : v_base{2} {}

    void method_inherit2(){
        std::cout << "inherit2_class:" << this << std::endl;
    }

};

class v_more_inherit: public v_inherit1, public v_inherit2{

public:
    v_more_inherit() : v_base{3} {}

};

//
// inhibit inheritances using "final" 
class f_base{

public:
    virtual void f_show(){
        std::cout << "f_base class" << std::endl;
    }

};

class f_inh : public f_base {

public:
    void f_show() final {
        std::cout << "f_inh class" << std::endl;
    }

    virtual void f_show1() {
        std::cout << "f_int_v method" << std::endl;
    }

};

class f_m_inh : public f_inh {

public:
/*
    void f_show() override{                             // "final" declarated function is not overrided anymore
        std::cout << "f_m_inh class" << std::endl;
    }
*/
    void f_show1() final {
        std::cout << "f_m_int_v method" << std::endl;
    }

};



//
// main routine
int main(){
    std::cout << "----- \"protect\" : access protection -----" << std::endl;
    inherit inh(35);
    inh.show();

    inherit_p inh_p;
    inh_p.show();

    std::cout << "----- inherited class can make base class ref & pointer -----" << std::endl;

    base_r base;

    inherit_r inh_r;

    inh_r.base_show();
    inh_r.inherit_show();

    base_r* ptr= &inh_r;            // if you change the order of this two lines, it causes an error, why?
    base_r& base_r = inh_r;

    base_r.base_show();             // base class reference call override function in the inherited class as a default
    ptr -> base_r::base_show();     // to call base class function, explicitly denote the base class

    auto r_ptr = allocate();        // base class allocated resource which is used in inherited class is released by inhrit destructor
    delete r_ptr;

    std::cout << "----- multiple inheritance -----" << std::endl;
    m_inherit m_inh;
    m_inh.m_base1::show();          // if multiple base class have same name of method, you need to explicitly define the class name
    m_inh.m_base2::show();
    m_inh.log();

    std::cout << "----- virtual base class for multiple inheritance, only one class instance is guranteed -----" << std::endl;
    v_more_inherit v_m_inh;
    v_m_inh.method_inherit1();
    v_m_inh.method_inherit2();

    v_inherit1& derive1 = v_m_inh;          // following two method call make same result, since only one base class instance is guranteed by virtual notation
    derive1.method_vb();                    // interest thing is the value is same as "v_inherit1 this" pointer

    v_inherit2& derive2 = v_m_inh;          // if inherit without "virtual", there are different value(instance address)
    derive2.method_vb();

    std::cout << "----- inheritance inhibition using final -----" << std::endl;
    f_m_inh f_m_ins;
    f_m_ins.f_show1();
    f_m_ins.f_base::f_show();

}
