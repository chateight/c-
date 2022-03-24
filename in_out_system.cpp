#include <iostream>

//
// main rooutine from here
int main(){
    auto deft = std::cout.flags();                  // save default flags
    
    std::cout << "----- output format -----" << std::endl;
    std::cout.setf(std::ios::scientific);
    std::cout << "scientific : " << 971.52f << std::endl;
    std::cout.setf(std::ios::hex);
    std::cout.unsetf(std::ios::dec);                // reset the decimal format to avoid ambiguous formatting, since "idec" was set as a default
    std::cout << "hex : " << 638 << std::endl;

    std::cout.setf(std::ios::hex, std::ios::basefield);             // basefield : dec/hex/oct are cleared, and set the field
    std::cout << "set basefield : " << 4282.98f << std::endl;       // previous "scientific" flag is still valid
    std::cout << 772340 << std::endl;
    std::cout.flags(deft);                                          // override flags()
    std::cout << "reset to dafault : " << 4282.98f << std::endl;
    std::cout << 772340 << std::endl;

}