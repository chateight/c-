#include <iostream>
#include <utility>

const long a_size = 1000000*100;

class home
{
    int* m_land;
    int* cp_land;

public:
    explicit home(long size)
        : m_land{new int[size] ()}{}
    
    ~home() { delete [] m_land;}

    home(home&& other);

    int* land() const { return m_land; }

    int* land_cp() const { return cp_land; }

    void copy()
    {
        cp_land = new int[a_size];
        for (int i = 0; i <= a_size; i++)
        {
            cp_land[i] = m_land[i];
        }
    }

    void del()
    {
        delete [] cp_land;
    }
};

home::home(home&& other)
    : m_land{other.m_land}
{
    other.m_land = nullptr;
}


int main()
{
    std::chrono::system_clock::time_point  start, end;
    start = std::chrono::system_clock::now();

    home A{a_size};
    std::cout << "A\'s land address : " << A.land() << std::endl;

    A.copy();
    std::cout << "A\'s cp_land address : " << A.land_cp() << std::endl;
    A.del();

    home B{std::move(A)};
    std::cout << "B\'s land address : " << B.land() << std::endl;

    std::cout << std::endl;
    end = std::chrono::system_clock::now();
    double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
    std::cout << "elapsed time : " << elapsed << " ms" << std::endl;
}