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

int main(){
    A a;
    a.set(32);

    const A& ca = a;        // ca is a reference to the instance a
    a.set(70);
    std::cout << "const function : " << ca.get() << std::endl;      // -> 70
}