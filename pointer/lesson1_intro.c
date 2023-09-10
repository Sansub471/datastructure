#include<stdio.h>

int main(){
    int a;
    int *p;
    p = &a;
    a = 5;
    printf("'p' has address     : %p\n", p);
    printf("The address of a is : %p\n", &a);
    printf("The address of p is : %p\n", &p);
    printf("The value of p is   : %d\n", *p);

    printf("The value of 'a' is : %d\n", a);
    *p = 77;
    // *p derefences the pointer, which means it accesses the memory location
    // pointed to by 'p' (which is the memory location of 'a'), and sets 
    // its value to '77'.
    printf("The value of 'a' is : %d\n", a);
    printf("\n");
    int b = 17;
    *p = b;
    printf("The address of p is   : %p\n", &p);
    printf("The value of 'p'is    : %d\n", *p);
    printf("The value of 'a'  is  : %d\n", a);
    printf("The address of 'a' is : %p\n", &a);
    printf("The address of 'b' is : %p\n", &b);
    return 0;
}