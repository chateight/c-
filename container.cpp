#include <iostream>
#include <vector>
#include <list>

//
// list output
void show_list(const std::list<int>& li){
    for (auto ite = li.begin(); ite != li.end(); ++ ite){
        std::cout << *ite << " ";
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

    auto gt = [](int x, int y){return x > y;};      // reverse sort
    li.sort(gt);                // higher order function call
    show_list(li);

}
