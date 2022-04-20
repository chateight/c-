#include <iostream>
#include <string>
#include <charconv>
#include <regex>

//
// main method from here
int main(){

    std::cout << std::endl;
    std::cout << "----- string basic -----" << std::endl;
    std::string str("where is a heaven?");

    std::string str_p(str, 10, std::string::npos);  // pick up the sub-string using new constructor
    std::cout << "substring is : "<< str_p << std::endl;

    char* chr = str.data();         // return the pointer of the first char of the char string
    std::cout << "first charactor is : " << *chr << std::endl;

    std::string a{"abcdefghijk"};
    std::string b{"abcdefghijl"};

    int ret = a.compare(b);
    std::cout << "compared result : " << ret << std::endl;  // b < a, since dictionsry order is applied

    str += " it's inside yours ";       // combine the strings
    std::cout << str << std::endl; 

    std::cout << std::endl;
    std::cout << "----- conversion between string and numeric -----" << std::endl;

    std::string st_i = std::to_string(218);
    std::cout << "integer to string : " << st_i << std::endl;

    float l_st = std::stof("64.189", nullptr);      // second argument "nullptr" does not need
    std::cout << "string to float : " << l_st << std::endl;

    std::cout << std::endl;
    std::cout << "----- basic regular expression -----" << std::endl;

    std::regex re{"\\d+"};                  // regex pattern definition
    std::string in = "fhgtg24tfhkgjo34442iphhyip";
    std::smatch match;                      // matched string
    
    while (std::regex_search(in, match, re)){
        std::cout << match.str() << std::endl;
        in = match.suffix();                // rest of the string after the matching
        std::cout << in << std::endl;
    }

    std::cout << std::endl;
    std::cout << "----- string replacement using regex -----" << std::endl;

    std::string st_rp{"c++ is used for hardware control and real time operation purpose. "};

    std::regex re_rp{"c[++]"};
    std::cout << std::regex_replace(st_rp, re_rp, "c & c++") << std::endl;

}