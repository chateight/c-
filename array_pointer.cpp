#include <iostream>
#include <vector>

using namespace std;        // only for convenience, not to use in actual case

// argument using array
void sum(int array[], int len){
    int sum = 0;
    for (int i = 0; i < len; ++i){
        sum += array[i];
    }
    cout << sum << endl;
}

// reverse the array(it looks legacy way)
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

    arr1.swap(arr2);            // using container class is easier, even in case of swap operation
    */
    return ret;
}

// dynamic object allocation
class d_alloc{
    float width;
    float height;

public:
    explicit d_alloc(float width, float height);
    float area() const;
};

d_alloc::d_alloc(float width, float height)
    : height(height), width(width)
{
}

float d_alloc::area() const
{
    return height*width/2;
}

// type deduction
int& ret_r(int& i_r){       // return the reference accepted as an argument
    return i_r;             // if you return the reference to the local variable, it causes severe problem since it would be destroyed after the last brace(life time issue)
}

// move construtor : main purpose is to use hardware resources effectively
class c_move{
    int* m_land;

public:
    explicit c_move(std::size_t size)
        : m_land{new int[size]} {}

    ~c_move() {
        cout << "destructor is called" << endl;
        delete [] m_land; 
    }

    c_move(c_move&& other);

    int* land() const {return m_land;}
};

c_move::c_move(c_move&& other)
    : m_land{other.m_land}          // copy the area pointer
{
    other.m_land = nullptr;         // set to null for the original pointer
}


int main(){
    //
    // implicit conversion to the pointer
    cout << "----- implicit pointer value of the array -----" << endl;
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
    //
    // dynamic object allocation( to control the life time, but need to destruct by yourself)
    cout << "----- dynamic allocation of the class instance -----" << endl;
    d_alloc* da = new d_alloc{10.0f, 7.0f};             // allocate class instance as a dynamic resource pointer
    cout << "area : "<< da -> area() << endl;
    delete da;                                          // to avoid memory leak, don't forget to release the allocated resource(class object)
    //
    // type deduction for the reference
    int i_r = 87;
    auto& j_r = ret_r(i_r);                 // type dudcution should be defined as a reference
    j_r = 65;
    cout << "change the value of the reference : " << i_r << endl;
    //
    // right hand side value reference

    //
    // move constructor(used for resource reduction)
    cout << "----- move constructor -----" << endl;
    c_move a_m{100};
    cout << "land address of the a_m : "<< a_m.land() << endl;

    c_move b_m{std::move(a_m)};                 // area owner change to b_m from a_m

    cout << "land address of the b_m : "<< b_m.land() << endl;
    cout << "land area of the a_m after move " << a_m.land() << endl;

}