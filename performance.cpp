#include <iostream>
#include <chrono>
#include <cmath>
#include <vector>

int main(){

int sqt;
bool flag;
std::vector<int> vec{};

std::chrono::system_clock::time_point  start, end;
start = std::chrono::system_clock::now();


for (int i = 2; i <= 1000000; ++i){         // check prime numbers
    flag = false;
    sqt = sqrt(i);
    for (int j = 2; j <= sqt; ++j){
        if (i%j == 0){
            flag = true;
            break;
        }
    } 
    if (flag != true){
        vec.push_back(i);
    }
}

end = std::chrono::system_clock::now();
double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();

 std::cout << elapsed << " ms" << ", number of prime numbers(up to 1M) : " << vec.size() << std::endl;

}

