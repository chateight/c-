#include <iostream>

// class with "const" function
class A{
    int v;

    public:
        void set(int val);
        int get() const;
};

void A::set(int val){
    v = val;
}

int A::get() const{
    return v;
}

// constructor & destructor
class c_class{
    int age;
    std::string name;

    c_class(int age, std::string name);                 // delegated constructor could be private scope

public:
    double *m_alloc;

    c_class();
    ~c_class();

    void set_name(std::string s_name);
    void set_age(int s_age);

    std::string g_name();
    int g_age();
};

c_class::c_class(int s_age, std::string s_name)         // delegated constructor                            
    :age(s_age), name(s_name)                           // initialize variables
{
    std::cout << "delegeted constructor is called " << std::endl;
}

c_class::c_class()                                      // constructor : if you don`t define it, compiler generate a default constructor
    :c_class(30, "bobby")                               // delegate to the "c_class(int age, std::string name)"
{
    m_alloc = new double[1000];                         // memory alloc
    std::cout << "constructor \"common\" is called " << std::endl;
}

c_class::~c_class(){                                    // destructor
    delete [] m_alloc;                                  // memory release
    std::cout << "destructor is called" << std::endl;   // destructor call timing is decided by c++ compiler
}

void c_class::set_age(int s_age){
    age = s_age;
}

std::string c_class::g_name(){
    return name;
}

int c_class::g_age(){
    return age;
}

int main(){
    A a;
    a.set(32);

    const A& ca = a;        // ca is a reference to the instance a
    a.set(70);
    std::cout << "--- constant function of the class ---" << std::endl;
    std::cout << "const function : " << ca.get() << std::endl;      // -> 70
    //ca.set(10);           // error, since it tries to change the const instance

    // constructor & destructor
    std::cout << "--- constructor & destructor ---" << std::endl;
    c_class cc;
    std::cout << "age : "<< cc.g_age() << std::endl;
    cc.set_age(28);
    std::cout << "name : "<< cc.g_name() << std::endl;
}