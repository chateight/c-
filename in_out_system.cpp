#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>

//
// basic file read write class
class file_IO{

    std::string file_name = "./io/d_file.txt";

public:
    void put(std::string str);
    std::string get();

};

void file_IO::put(std::string str){
    std::ofstream out;
    out.open(file_name, std::ios::app); // use append mode
    if (out.is_open()){                 // file opened?
        out << str << std::endl;
        out.close();                        // even if you miss the close call, destructor will release it
    }
    else{
        std::cout << "t_file open error" << std::endl;
    }
    return;
}

std::string file_IO::get(){
    std::string str;
    std::ifstream in{file_name};        // constructor and file open can be excuted in one line
    if (in.is_open()){
        while(!in.eof()){                   // read to the end of the file
            std::string tmp;
            std::getline(in, tmp);
            str += tmp;
        }
    }
    else{    
        std::cout << "t_file open error" << std::endl;
    }
    in.close();
    return str;
}

//
// binary data read/write
class b_file_IO{

    std::string file_name = "./io/d_file.bin";

public:
    void put(char* char_s, int len);
    std::string get();

    int count = 0;      // read char counter

};

void b_file_IO::put(char* str, int len){
    std::ofstream out{file_name, std::ios::binary};     // use binary mode
    if (out.is_open()){
        out.write(str, len);
        out.close();
    }
    else{
        std::cout << "b_file open error" << std::endl;
    }
    return;
}

std::string b_file_IO::get(){
    char str[100];
    std::ifstream in{file_name};        // constructor and file open can be excuted in one line
    if (in.is_open()){
        in.read(str, 100);
        count = in.gcount();            // set the char buffer counter
    }
    else{    
        std::cout << "b_file open error" << std::endl;
    }
    in.close();
    return str;
}


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
    std::cout << "----- using IO manipulator -----" << std::endl;
    std::cout << std::scientific << std::setprecision(6) << M_PI << std::endl;
    std::cout << M_PI << std::endl;                                 // manipulator is available for the succeeding statements
    std::cout << std::dec << std::setfill('0') << std::setw(9) << 87543 << std::endl;


    std::cout << std::endl;
    std::cout << "----- consol input -----" << std::endl;

    char buff[256];
    while(true){
        std::cin.getline(buff, 256);                                // consol input
        if (*buff != '\0'){                                         // empty(return only)?  ; "*buff" or "buff[0]" has the same meaning
            std::cout << "input : " << buff << std::endl;
        }
        else{
            break;                              // if input was empty -> break
        }
    }


    std::cout << std::endl;
    std::cout << "----- basic file r//w -----" << std::endl;
    file_IO fio;
    fio.put(" here is a sample of the file read and write");
    std::cout << fio.get() << std::endl;


    std::cout << std::endl;
    std::cout << "----- binary file r//w -----" << std::endl;
    b_file_IO b_fio;
    
    char str[] = {'h','e','r','e',' ','i','s',' ','a',' ','s','a','m','p','l','e',' ','o','f',' ','t','h','e',' ','b','i','n','a','r','y','\0'};
    b_fio.put(str, sizeof(str));
    std::cout << b_fio.get() << " , char count : " << b_fio.count << std::endl;

}