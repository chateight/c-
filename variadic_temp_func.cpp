#include <iostream>

template <typename... Args>
void func2()
{
    std::cout << "no arg func is called\n" << std::endl;
}

template <typename Head, typename... Body>
void func2(Head head, Body... body)
{
    std::cout << head << "\t" << sizeof...(body) << "\n";

    func2(body...);         // recursive call 
}

int main()
{
    func2("foo", "bar", "hoge", "huga");
    func2("one", "two", "three");
    func2();
}