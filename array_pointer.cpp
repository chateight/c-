#include <iostream>

using namespace std;

// argument using array
void sum(int array[], int len){
    int sum = 0;
    for (int i = 0; i < len; ++i){
        sum += array[i];
    }
    cout << sum << endl;
}

int main(){
    //
    // implicit conversion to the pointer
    cout << "----- implicit to the pointer value of the array -----" << endl;
    int array[] = {0, 1, 2, 3, 4, 5};   //int array has four bytes elements

    int* ptr = &array[0];       // "&array[0]"" is same as "array"

    cout << "top adress of the array : " << ptr << endl;

    ptr = array;

    cout << "to get implicit address : " << ptr << endl;
    //
    // next address
    const char* p_str = "abcde";

    cout << *(ptr + 1) << endl;     // access to the array[1], though the element size is four bytes
    cout << ptr[1] << endl;         // ptr[1] has the same meaning

    cout << "to get array string char from the pointer" << endl;
    cout << *(p_str + 1) << endl;    
    cout << p_str[1] << endl;       // same as  above
    //
    // argument using array
    cout << "----- array as an argument -----" << endl;
    int i_array[] = {2, 4, 6, 8, 10, 12};
    sum(i_array, sizeof(i_array)/sizeof(int));
    //
    // pointer andd reference of the array
    cout << "----- pointer & ref -----" << endl;
    int p_array[] = {1, 2, 3, 4, 5};
    int (*p_ptr)[5] = &p_array;

    for (int v : *p_ptr){
        cout << v << endl;
    }
    cout << endl;

    int (&p_ref)[5] = p_array;

    for (int v : p_ref){
        cout << v << endl;
    }
}