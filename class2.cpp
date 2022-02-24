#include <iostream>

using namespace std;


// inherit sample

// base class
class base{

    int v1_base = 29;
    string v1_str = "base class";

public:
    void v1_i_set(int val);
    void v1_s_set(string str);
    int v1_i_get();
    string v1_s_get();

    virtual int calc(int a, int b);
};

void base::v1_i_set(int val){
    v1_base = val;
}

void base::v1_s_set(string str){
    v1_str = str;
}

int base::v1_i_get(){
    return v1_base;
}

string base::v1_s_get(){
    return v1_str;
}

int base::calc(int a, int b){
    return a + b;
}

// inherit class
class inherit : public base{        // define ancestor class access spcifier to use ancestor class resouces
    string v2_str = "inherit class";

public:
    void v2_s_set(string str);
    string v2_s_get();

    int calc(int a, int b) override;

};

void inherit::v2_s_set(string str){
    v2_str = str;
}

string inherit::v2_s_get(){
    return v2_str;
}

int inherit::calc(int a, int b){
    return a*b;
}

// main process from here
int main(){
inherit ih;
cout << "----- inherit -----" << endl;
cout << ih.v2_s_get() << endl;
cout << ih.v1_s_get() << endl;      // inherit class can use ancestor class method if it is defined as a global scope
base bs;
cout << "inherit func result : "<< ih.calc(102, 204) << endl;  // inhrit instance uses overide method
cout << "ancestor func result : " << bs.calc(102, 204) << endl;  // ancestor instance uses original method
}