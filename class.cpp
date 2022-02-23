#include <iostream>

using namespace std;

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

// constructor, copy-constructor & destructor
class c_class{
    int age = -1;               // set to meaningless value
    string name = "hoge";       //

    c_class(int age, string name);                  // delegated constructor could be private scope
 
public:
    double *m_alloc;

    explicit c_class();
    explicit c_class(const c_class& cp);                     // copy constructor
    ~c_class();

    void set_name(string s_name);
    void set_age(int s_age);

    string g_name() const;
    int g_age() const;
};

c_class::c_class(int s_age, string s_name)          // delegated constructor                            
    :age(s_age), name(s_name)                       // initialize variables
{
    cout << "delegeted constructor is called " << endl;
}

c_class::c_class()                                      // constructor : if you don`t define it, compiler generate a default constructor
    :c_class(30, "bobby")                               // delegate to the "c_class(int age, string name)"
{
    m_alloc = new double[1000];                         // memory alloc
    cout << "constructor \"common\" is called " << endl;
}

c_class::~c_class(){                                    // destructor
    delete [] m_alloc;                                  // memory release
    cout << "destructor is called" << endl;     // destructor call timing is decided by c++ compiler
}                                               // called twice, since we make two instances

c_class::c_class(const c_class& cp){
    cout << "copy constructor is called" << endl;        // "constant" is used to protect original instance
    m_alloc = new double[1];                    // need to copy resource allocation of the original instance
    set_name(cp.g_name());
    set_age(cp.g_age());                        // "age = cp.g_age();"" acts as same as above
}

void c_class::set_age(int s_age){
    age = s_age;
}

void c_class::set_name(string s_name){
    name = s_name;
}

string c_class::g_name() const{
    return name;
}

int c_class::g_age() const{
    return age;
}


// main process from here
int main(){
    A a;
    a.set(32);

    const A& ca = a;        // ca is a reference to the instance a
    a.set(70);
    cout << "--- constant function of the class ---" << endl;
    cout << "const function : " << ca.get() << endl;    // -> 70
    //ca.set(10);           // error, since it tries to change the const instance

    // constructor & destructor
    cout << "--- constructor & destructor ---" << endl;
    c_class cc;
    c_class cp(cc);                                     // "c_class cp = cc;" does not work since the constructor was defined as explicit
    cout << "age : "<< cp.g_age() << endl;              // access to the copied instance
    cc.set_age(28);
    cout << "name : "<< cc.g_name() << endl;
}