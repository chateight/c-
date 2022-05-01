#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <cmath>

std::mutex mtx_;                // mutex for exclusive control
std::vector<int> vec{};         // prime numbers array
int cal_int = 1;                // calc target integer
int max_int = 10000000;          // calc target max number


void add_prime(int i)
{
    std::lock_guard<std::mutex> lock(mtx_);
    vec.push_back(i);
}

int get_int()
{
    std::lock_guard<std::mutex> lock(mtx_);
    ++cal_int;
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
        for (int j = 2; j <= sqt; ++j){
            if (i%j == 0){
                flag = true;
                break;
            }
        }
        if (flag != true){
            add_prime(i);
        }
    }
}

void ThreadB()
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
        for (int j = 2; j <= sqt; ++j){
            if (i%j == 0){
                flag = true;
                break;
            }
        }
        if (flag != true){
            add_prime(i);
        }
    }
}

void ThreadC()
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
        for (int j = 2; j <= sqt; ++j){
            if (i%j == 0){
                flag = true;
                break;
            }
        }
        if (flag != true){
            add_prime(i);
        }
    }
}

void ThreadD()
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
        for (int j = 2; j <= sqt; ++j){
            if (i%j == 0){
                flag = true;
                break;
            }
        }
        if (flag != true){
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

    std::thread th_a(ThreadA);
    std::thread th_b(ThreadB);
    std::thread th_c(ThreadC);
    std::thread th_d(ThreadD);

    th_a.join();
    th_b.join();
    th_c.join();
    th_d.join();

    std::cout << std::endl;
    end = std::chrono::system_clock::now();
    double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
    std::cout << "elapsed time : " << elapsed << " ms" << std::endl;

    std::sort(vec.begin(), vec.end() );
    for (auto itr = (vec.end() - 5); itr != vec.end(); ++itr){
    std::cout << *itr << std::endl;
    }

    return 0;
}