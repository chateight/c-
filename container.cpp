#include <iostream>
#include <vector>

int main(){

    std::cout << std::endl;
    std::cout << "----- container class : vector  -----" << std::endl;

    std::vector<int> v0 = {1, 2, 3, 4, 5};

    v0.push_back(6);            // by the push
    v0.insert(v0.end(), 7);     // by the insert

    for (int i : v0){
        std::cout << " " << i << std::endl;
    }

    std::cout << std::endl;                     
    for (auto iter = v0.rbegin(); iter != v0.rend(); ++iter){   // reverse access
        std::cout << " " << *iter << std::endl;
    }
}
