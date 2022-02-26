#include <iostream>

using namespace std;

// pure virtual
class calc{                     // abstract class which could not be instanciated

public:
    virtual float area_calc() const = 0;        // define pure virtual function
    virtual float peri_calc() const = 0;
};

// c_2d class
class c_2d : public calc{       // rectangle area and total side
    float width;
    float height;

public:
    explicit c_2d(float a, float b);

    float area_calc() const override;
    float peri_calc() const override;

};

c_2d::c_2d(float a, float b)
    : width(a), height(b)
{
}

float c_2d::area_calc() const{
    return width*height;
}

float c_2d::peri_calc() const{
    return (width+height)*2;
}

// box class
class box : public calc{        // box surface total area and total side
    float width;
    float height;
    float depth;

public:
    explicit box(float a, float b, float c);
 
    float area_calc() const override;
    float peri_calc() const override;

};

box::box(float a, float b, float c)
    : width(a), height(b), depth(c)
{
}

float box::area_calc() const{
    return (width*height+height*depth+ width*depth)*2;
}

float box::peri_calc() const{
    return (width+height+depth)*4;
}

// object as a pointer & this pointer, it looks as an extention of the usual pointer
class p_class_base{

    string str = "initial string";

public:
    void prn(string str);
};
void p_class_base::prn(string str){
    this-> str = str;           // set augment "str" to the local string "str"
    cout << "accepted string : " << this->str << endl;  // "this" means class p_class_base pointer
}

void p_call(p_class_base* poi, string st){
    poi->prn(st);
}

int main(){
    c_2d a(10, 20);
    cout << "----- pure virtual -----" << endl;
    cout << "area : " << a.area_calc() << endl;
    cout << "total side : " << a.peri_calc() << endl;
    box b(20, 30, 40);
    cout << "total area : " << b.area_calc() << endl;
    cout << "total side : "<< b.peri_calc() << endl;

    p_class_base pt;
    cout << "----- object as a pointer -----" << endl;
    p_call(&pt, "check the object pointer");
}

