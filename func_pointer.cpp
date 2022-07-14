/*
 from http://pract.webcrow.jp/pages/contents/c/pointer/pointer-of-func
*/
#include <stdio.h>
#include <stdlib.h>

typedef void (*FUNC_POINTER)(int, int);     // obsolete style, "using" is for c++ @next line, it's more readable
//using FUNC_POINTER = void (*)(int, int); 

// callback function
void add(int a, int b){
    printf("a + b = %d\n", a + b);
}

void sub(int a, int b){
    printf("a - b = %d\n", a - b);
}

void calc(int a, int b, FUNC_POINTER p){        // using callback function
    (*p)(a, b);
}
//
// function pointer
void start(){
    printf("Start\n");
}

void save(){
    printf("Save\n");
}

void end(){
    printf("End\n");
    exit(0);
}

void (*menu[])() ={                             // define the function pointer array
    start, save, end
};

int main(){
    //
    // run the callback function example
    FUNC_POINTER p;
    p = add;
    calc(100, 100, p);
    p = sub;
    calc(100, 100, p);
    //
    // run the funcion pointer example
    // console input number 1,2,3(exit) defines pointer of the function array
    while(1){
        int i = getchar();
        i -= '0' + 1;
        if( 0 <= i && i < 3 )
            menu[i]();
    }

    return 0;
}
