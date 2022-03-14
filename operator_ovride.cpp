#include <iostream>

// basic operator overload
class Float{
    float val;

public:
    Float(float val) : val(val){}

    Float operator+(const Float& rf) const;
    Float operator-(const Float& rf) const;

    Float operator+() const;        // return the sign of the variable
    Float operator-() const;

    void show() const;
};

Float Float::operator+(const Float& rf) const{
    return Float(val + rf.val);
}

Float Float::operator-(const Float& rf) const{
    return Float(val - rf.val);
}

Float Float::operator+() const{
    return *this;
}

Float Float::operator-() const{
    return Float(-val);
}

void Float::show() const{
    std::cout << val << std::endl;
}


int main(){
    std::cout << "----- basic operator override(floating plus & minus) -----" << std::endl;
    Float x = 7.34f;
    Float y = 5.17f;

    auto v = x + y;
    v.show();

    auto w = x - y;
    w.show();

    auto p = +x;
    p.show();

    auto q = -x;
    q.show();

}