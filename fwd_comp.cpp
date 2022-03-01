#include <iostream>

using namespace std;

// forward declaration
int sum(int a, int b);          // declaration, definition is at bottom of this source


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


int main(){
    cout << "------ forward declaration ------" << endl;
    cout << sum(20, 81) << endl;

    // call the combined function
    com i_com(32, 67);
    cout << "------ call the combined declaration and definition ------" << endl;
    cout << i_com.sum() << endl;
}

// dorward declaration continued
int sum(int a, int b){          // definition
    return a + b;
}
