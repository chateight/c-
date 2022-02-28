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

// object as a pointer & "this" pointer, it looks as an extention of the usual pointer
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

// friend function
class vector3d{
    float x;
    float y;
    float z;

public:
    vector3d();
    explicit vector3d(float x, float y, float z);
    friend vector3d add(const vector3d& lhs, const vector3d& rhs);      // friend function

    void dump() const; 
};

vector3d::vector3d()
    : vector3d(0,0,0)
{
}

vector3d::vector3d(float x, float y, float z)
    : x(x), y(y), z(z)
{
}

vector3d add(const vector3d& lhs, const vector3d& rhs){     // description of the friend function which is an external function, not a member function
    vector3d result;                                        // it accepts pointer of the class or refernce, since it is not a member of the class
    result.x = lhs.x + rhs.x;
    result.y = lhs.y + rhs.y;
    result.z = lhs.z + rhs.z;
    return result;
}

void vector3d::dump() const{
    cout << x << ", " << y << ", " << z << endl;
}

// static member and function
class s_class{

    static int count;

public:
    s_class();
    ~s_class();

    static void show_count();
};

int s_class::count = 0;

s_class::s_class(){
    ++count;
}

s_class::~s_class(){
    --count;
}

void s_class::show_count(){
    cout << "static count : " << count << endl;
}

int main(){
    c_2d a(10, 20);
    cout << "----- pure virtual -----" << endl;
    cout << "area : " << a.area_calc() << endl;
    cout << "total side : " << a.peri_calc() << endl;
    box b(20, 30, 40);
    cout << "total area : " << b.area_calc() << endl;
    cout << "total side : " << b.peri_calc() << endl;

    p_class_base pt;
    cout << "----- object as a pointer -----" << endl;
    p_call(&pt, "check the object pointer");

    cout << "----- \"anonymous union\"(later, if it is needed) -----" << endl;

    cout << "----- \"friend function\" which can access local variables unless it is not a member function -----" << endl;
    vector3d fa(1,1,1), fb(1,2,4);
    vector3d fc = add(fa, fb);
    fc.dump();

    cout << "----- static member & function -----" << endl;
    s_class::show_count();                  // when you make instance with "for" loop, its behavior is strange due to the destructor?
    s_class ins1;
    s_class::show_count();
    s_class ins2;
    s_class::show_count();
}

