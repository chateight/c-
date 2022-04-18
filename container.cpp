#include <iostream>
#include <vector>
#include <list>
#include <tuple>
#include <set>
#include <map>
#include <algorithm>

//
// list output
void show_list(const std::list<int>& li){
    for (auto ite = li.begin(); ite != li.end(); ++ ite){
        std::cout << *ite << " ";
    }
    std::cout << std::endl;
}

//
// find "set" element function
void find_s(std::set<int>& st, int num){
    auto pt = st.find(num);             // find() returns "end()" pointer if it was not found
    if (pt == st.end()){
        std::cout << " a search result was not found " << std::endl;
    }
    else{
        std::cout << " result is : " << *pt << std::endl;
    }
}

//
// higher order function in the algorythms
template <typename T>
void s_show(const std::vector<int>& array, T prep){      // prep is a function object

    for (int i: array){
        if (prep(i)){
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
}


//
// main function from here
int main(){

    std::cout << std::endl;
    std::cout << "----- container class : vector  -----" << std::endl;

    std::vector<int> v0 = {1, 2, 3, 4, 5};

    v0.push_back(6);            // by the push
    v0.insert(v0.end(), 7);     // by the insert

    for (int i : v0){
        std::cout << " " << i;
    }
    std::cout << std::endl;

    std::cout << std::endl;                     
    for (auto iter = v0.rbegin(); iter != v0.rend(); ++iter){   // reverse access
        std::cout << " " << *iter ;
    }
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "----- container class : list  -----" << std::endl;

    std::list<int> li = {5, 6, 1, 23, 32, 9, 3, 8, 3, 52};

    li.sort();
    show_list(li);

    std::cout << std::endl;
    auto gt = [](int x, int y){return x > y;};      // reverse sort( "x = y" produces a same output)
    li.sort(gt);                // higher order function call
    show_list(li);

    std::cout << std::endl;
    std::cout << "----- tuple & structured binding -----" << std::endl;
    std::tuple tu{std::string{"tuple"}, 72.3f, 93};         // you can use a raw string "tuple" instead of the string constructor

    auto& [a, b, c] = tu;       // copy or reference is available 

    std::cout << a << ", " << b << ", " << c << std::endl;

    std::cout << std::endl;
    std::cout << "----- container class : set -----" << std::endl;

    std::set st = {4,1,5,6,7,3,7,8,9,1,2};          // "set" does not permit same value in the menber, same values are degenerated

    st.insert(12);
    auto s_ptr = st.begin();
    std::cout << "size of the set : "<< st.size() << std::endl;
    while (s_ptr != st.end()){

        std::cout << *s_ptr << " ";
        ++s_ptr;
    }
    std::cout << std::endl;

    find_s(st, 10);
    find_s(st, 12);

    std::cout << std::endl;
    std::cout << "----- container class : map -----" << std::endl;

    std::map ma = {
        std::pair{"inpulse", 2},
        std::pair{"red stone", 3},
    };

    for (const auto& [key, val] : ma){
        std::cout << key << " : " << val << std::endl;
    }

    std::cout << std::endl;
    auto pt = ma.find("inpulse");

    if (pt == ma.end()){
        std::cout << "the search result was not found " << std::endl;
    }
    else{
        const auto& [key, val] = *pt;
        std::cout << "the result is : " << val << std::endl;
    }

    std::cout << std::endl;
    std::cout << "----- higher order function for algorythms -----" << std::endl;

    std::vector<int> array = {6, 2, 3, 7, 6, 8, 1, 6, 9, 23};

    s_show(array, [](int v) {return v < 10;});      // delta function ; if element is less than 10

    int cnt = std::count_if(array.begin(), array.end(), [array](int i){return i == array[0];}) - 1;
    std::cout << "number of matching elements with the top : " << cnt << std::endl;

}
