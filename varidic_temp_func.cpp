#include <iostream>

template <class... Args>
void func2()
{
    std::cout << "no args func is called\n" << std::endl;
}

template <class Head, class... Body>
void func2(Head head, Body... body)
{
    std::cout << head << "\t" << sizeof...(body) << "\n";

    func2(body...);
}

int main()
{
    func2("foo", "bar", "hoge", "huga");
    func2();
}