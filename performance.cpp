#include <iostream>
#include <chrono>
#include <cmath>

bool flag;
int main(){
std::chrono::system_clock::time_point  start, end;
start = std::chrono::system_clock::now();

int sqt = 0;
for (int i = 1; i <= 1000000; ++i){         // check prime numbers
    flag = false;
    sqt = sqrt(i);
    for (int j = 2; j <= sqt; ++j){
        if (i%j == 0){
            flag = true;
            break;
        }
    } 
    if (flag != true){
        std::cout << i << std::endl;
    }
}

end = std::chrono::system_clock::now();
double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();

 std::cout << sqt << " " << elapsed << " ms" <<std::endl;

}

