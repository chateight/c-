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
}