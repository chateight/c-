#include <iostream>
#include <cmath>

//
// main rooutine from here
int main(){
    auto deft = std::cout.flags();                  // save default flags
    
    std::cout << std::endl;
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

    std::cout <<std::endl;
    std::cout.precision(10);                                        
    std::cout << "pi = " << M_PI << std::endl;                      // PI
    std::cout.setf(std::ios::scientific);
    std::cout << "pi(scientific) = " << M_PI << std::endl;          // it seems the definition of "precision" is different at "scientific" mode


    std::cout.width(12);
    std::cout.setf(std::ios::oct, std::ios::basefield);             // set octal print
    std::cout.fill('-');                                            // filler "-"
    std::cout << "octal & filler : "<< 3577957 << std::endl;

    std::cout << std::endl;
    std::cout << "----- consol input -----" << std::endl;

    char buff[256];
    while(true){
        std::cin.getline(buff, 256);                                // consol input
        if (*buff != '\0'){                                         // empty(return only)?  ; "*buff" or "buff[0]" has the same meaning
            std::cout << "input : " << buff << std::endl;
        }
        else{
            break;                              // if empty -> break
        }
    }

}