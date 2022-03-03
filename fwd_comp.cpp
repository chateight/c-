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
    inline inline_s();                      // "inline" instructs to deploy the result of mini function into the called code

    void set_i(int i){
        this -> i = i;
    }

    void show() const;
};
    inline_s::inline_s() : i(1) {}

void inline_s::show() const{
    cout << i << endl;
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
}                                           // destructor for the "sc-i0" is called at the end of the "main" brace 

// forward declaration continued
int sum(int a, int b){          // definition
    return a + b;
}
