// As the name suggests, they are used to store the address of functions
// So far, we have used pointers to store the address of variables
// Hence, pointers can point to data
// pointer can point to functions

// Function pointer in C/C++
#include<stdio.h>

void PrintHello(char* name){
    printf("Hello %s\n", name);
}

int Add(int a, int b){
    return a+b;
}

// int* Func(int, int); // delcaring a function that would return int*
// But, 
// int (*Func)(int, int) // this is a function pointer

int main(){
    int (*p)(int, int); // arguments type of the function

    //int* p(int, int) it would mean we are declaring a function
    // that would return int* 

    p = &Add;
    int c = (*p)(2,3); // de-referencing and executing the function
    printf("The sum is : %d\n", c);

    // Another method 
    // p = Add; // would mean same as p = &Add
    // Then, 
    // int c = p(2,3); // de-referencing and executign the function
    // function pointer being used as function call
    // This method is more popular

    // to be able to point to a function, the type of the function pointer
    // must be appropriate
    // e.g void (*p)(int, int); // means the functin is returning void

    void (*hello)(char*);
    hello = PrintHello;
    hello("Subash");
    return 0;
}