#include <iostream>
#include <vector>

using namespace std;

// argument using array
void sum(int array[], int len){
    int sum = 0;
    for (int i = 0; i < len; ++i){
        sum += array[i];
    }
    cout << sum << endl;
}

// reverse the array
int* reverse(int array[10], int len){
    int array_r[10];                    // reverse work array larger size than the argument array
    int* ret = array;                   // set the pointer to the argument array
    int* ptr = array_r;                 // set the pointer of the reverse work array
    for (int i = 0; i < len; ++i){      // reverse copy to the reversework
        ptr[i] = ret[len - 1 -i];
    }

    for (int i = 0; i < len; ++i){      // set to the argument array
        ret[i] = ptr[i];
    } 
    /*    
    std::array<int, 3> arr1{ 1, 2, 3 };
    std::array<int, 3> arr2{ 4, 5, 6 };

    arr1.swap(arr2);            // using container class is easier for swap operation
    */
    return ret;
}


int main(){
    //
    // implicit conversion to the pointer
    cout << "----- implicit to the pointer value of the array -----" << endl;
    int array[] = {0, 1, 2, 3, 4, 5};   //int array has four bytes elements
    int* ptr = &array[0];               // "&array[0]"" is same as "array"

    cout << "top adress of the array : " << ptr << endl;

    ptr = array;                    // implicit conversion

    cout << "to get implicit address : " << ptr << endl;
    const char* p_str = "abcde";    // pointer as a "char*"

    cout << *(ptr + 1) << endl;     // access to the array[1]
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
    //
    // use an array as an arugment
    cout << "----- reverse the array -----" << endl;
    int r_array[5] = {5, 4, 3, 2, 1};
    reverse(r_array, 5);
    for (int i = 0; i < 5; ++i){
        cout << r_array[i] << endl;
    }
    //
    //　dynamic array(container class : more abstract and safer than primitive array)  
    cout << "----- dynamic array(vector) -----" << endl;
    vector<int> empty;
    cout << "empty size : " << empty.size() <<endl;

    vector<int> v_array = {20, 10, 50, 70, 15};
    cout << "v_array size : "<< v_array.size() << endl;

    for (int ele : v_array){
        cout << "element : " << ele << endl;
    }

    empty.push_back(21);
    empty.push_back(18);

    for (int ele : empty){
        cout << "empty element_push : " << ele << endl;
    }

    empty.pop_back();

    for (int ele : empty){
        cout << "empty element_pop : " << ele << endl;
    }
}