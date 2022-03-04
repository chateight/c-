#include <iostream>

using namespace std;

// forward declaration
int sum(int a, int b);          // declaration, definition is at the bottom of this code


// combine the declaration & definition
// for the large size source code, this style makes it not-readable
class com{

    int a;
    int b;

public:
    com(int a, int b){
        this -> a = a;
        this -> b = b;
    }

    int sum(){
        return a + b;
    }
};


// scope applicable area is checked by using destructor
// basically brace specifies available scope
class scope{

public:
    ~scope();

    void increment();
};

scope::~scope(){
    cout << "destructor was called" << endl;
}

void scope::increment(){
    static int init = 0;                    // static variable s not reinitialized
    cout << "init = " << init << endl;
    init++;
}

// inline function
class inline_s{
    int i;

public:
    inline inline_s();                      // "inline" instructs to deploy the result of mini function into the called code depending on the complexity of the code

    void set_i(int i){
        this -> i = i;
    }

    void show() const;
};
    inline_s::inline_s() : i(1) {}

void inline_s::show() const{
    cout << i << endl;
}

// name space
namespace a{
    int i = 67;

    void show(){
        cout << "@namespace a, int i = " << i << endl;
    }
}

namespace b{
    int i = 49;

    void show(){
        cout << "@namespace b, int i = " << i << endl;
    }
}

// class for macro function
class macro{
    int a;
    int b;

public:
void add(int a, int b);
void sub(int a, int b);

};

void add(int a, int b){
    cout << "add : " << a+b << endl;
}

void sub(int a, int b){
    cout << "sub : " << a-b << endl;
}


// main function from here
int main(){
    cout << "------ forward declaration ------" << endl;
    cout << sum(20, 81) << endl;

    // call the combined function
    com i_com(32, 67);
    cout << "------ call the combined declaration and definition ------" << endl;
    cout << "value i = " << i_com.sum() << endl;

    // scope
    cout << "------ scope ------" << endl;
    scope sc_i0;
    for (int i = 0; i < 5; i++){
        scope sc_i;
        sc_i.increment();                   // at end of the brace of the "for" loop, the destructor is called
    }

    // inline function
    cout << "----- inline function -----" << endl;
    inline_s i_i;
    i_i.show();
    i_i.set_i(21);
    i_i.show();

    // namespace
    cout << "----- name space -----" << endl;
    {
        using namespace a;
        show();                             // if there is no "using namespace", you need to define namespace like "a::show()"
    }
    {
        using namespace b;
        show();
    }

    // pre processor
    cout << "----- pre processor -----" << endl;
    #define hoge
    #if defined(hoge)                       // "#ifdef hoge" has same meaning in this case 
        cout << "true" << endl;
    #else
        cout << "false" << endl;
    #endif

    // include gurard
    #ifndef unique_header
    #define unique_header
    #endif

    // using macro
    cout << "----- using macro -----" << endl;
    add(10, 20);
    #define add sub
    add(30, 21);
}                                           // destructor for the "sc-i0" is called at the end of the "main" brace 


// forward declaration continued
int sum(int a, int b){          // definition
    return a + b;
}
