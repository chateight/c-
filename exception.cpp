#include <iostream>
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
// main method from here
int main(){

    try{
        exc_buf();
    }

    catch(int i){
        std::cout << "kind of exception is an integer exception: " << i << std::endl;
    }

    catch(...){
        std::cout << "an exception was occured " << std::endl;
    }
}