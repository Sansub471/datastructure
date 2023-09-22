// the usecase is based around the fact that function pointers can
// be passed to a function as argument
#include<stdio.h>

void A(){
    printf("Hello World!\n");
}


void B(void (*ptr)()) // function pointer as argument
{
    ptr(); // call-back function that "ptr" points to
}
int main(){
    void (*p)() = A; // try &A
    B(p);

    // Following statement is same as previous two statements
    B(A); 
    // Function A is being passed to another function B
    // A is called a call-back function

    // But, what's the point of calling A from B?
    return 0;
}