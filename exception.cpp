#include <iostream>
#include <exception>
//
//
void exc_source(){
    std::cout << "exc_source" << std::endl;
    throw 0;
}

void exc_buf(){
    try{
        exc_source();
    }
    catch(...){
        std::cout << "some kind of exception was catched" << std::endl;     // all kind of exception was catched here
        throw;          // rethrown exception to sort out the detail
    }
}

//
// custum exception class
class s_except : public std::exception{     // inherit base exception class

    const char* mes;

public:
    explicit s_except(const char* mes);
    const char* what() const noexcept override;
};

s_except::s_except(const char* mes)
    :mes{mes}{}

const char* s_except::what() const noexcept{
    return mes;
}

//
// exception in the constructor
class ex_con{


    int e = -99;

public:
    ex_con(){}

    ex_con(int e): e(e){
    std::cout << "ex_con const was called" << std::endl;
    if (e > 5){
        throw e;
        }
    }

    ~ex_con(){
    std::cout << "ex_con dest was called" << std::endl;
    }
};


//
// main method from here
int main(){

    std::cout << "----- exception using catch(...) -----" <<std::endl;

    try{
        exc_buf();
    }

    catch(int i){
        std::cout << "the kind of exception is an integer exception: " << i << std::endl;
    }

    catch(...){
        std::cout << "an exception was occured " << std::endl;      // do not reach to here
    }

    std::cout << std::endl;
    std::cout << "----- exception using catch(...) -----" <<std::endl;

    try{
        throw s_except{"generate the customized exception "};
    }
    catch(s_except& ex){
        std::cout << ex.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "----- exception in a constructor -----" <<std::endl;

    try{
        ex_con* ary = new ex_con[3];
        ary[0] = ex_con{0};
        ary[1] = ex_con{1};
        ary[2] = ex_con{10};
    }
    catch(int e){
        std::cout << e << std::endl;

    }



}