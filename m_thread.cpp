#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <cmath>

std::mutex mtx_;                // mutex for exclusive control
std::vector<int> vec{};         // prime numbers array
int cal_int = 1;                // calc target integer
int max_int = 10000000;         // calc target max number


void add_prime(int i)           // store the prime numberns in the vector
{
    std::lock_guard<std::mutex> lock(mtx_);
    vec.push_back(i);
}

int get_int()                   // get the integer to be tested
{
    std::lock_guard<std::mutex> lock(mtx_);
    ++cal_int;
    if (cal_int > 2 && cal_int%2 == 0)      // do not return an even number larger than four
    {
        ++cal_int;
    }
    return cal_int;
}

void ThreadA()
{
    while (true)
    {
        bool flag = false;
        int i = get_int();
        if (i > max_int)
        {
            break;
        }
        int sqt = sqrt(i);
        for (int j = 2; j <= sqt; ++j)
        {
            if (i%j == 0)
            {
                flag = true;
                break;
            }
        }
        if (flag != true)
        {
            add_prime(i);
        }
    }
}

int main()
{
    std::chrono::system_clock::time_point  start, end;
    start = std::chrono::system_clock::now();

    std::cout << std::endl;
    std::cout << "Hardware concurrency = " << std::thread::hardware_concurrency() << std::endl;

    std::vector<std::thread> threads;       // array of threads
    int num_thread = 12;                    // number of threads
    for(size_t i=0; i < num_thread; ++i){
        threads.emplace_back(std::thread(ThreadA));
    }

    for(auto& thread : threads){
        thread.join();
    }

    std::cout << std::endl;
    std::cout << "Number of threads = " << num_thread << std::endl;

    std::cout << std::endl;
    end = std::chrono::system_clock::now();
    double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
    std::cout << "elapsed time : " << elapsed << " ms" << std::endl;

    std::cout << std::endl;
    std::cout << "number of prime numbers : " << vec.size() << std::endl;

    std::cout << std::endl;
    std::cout << "last five prime numbers" << std::endl;
    std::sort(vec.begin(), vec.end() );
    
    for (auto itr = (vec.end() - 5); itr != vec.end(); ++itr)
    {
        std::cout << *itr << std::endl;
    }

}