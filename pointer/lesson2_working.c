#include<stdio.h>

// pointer arithematic
int main(){
    int a = 10;
    int* p;
    p = &a;

    // pointer arithmetic
    printf("p points Address of  is HEX : %p \t INT : %ld\n", (void*)p, (long int)(__intptr_t)p);
    // intptr_t to cast the pointer 'p' to an integer type before using %d
    printf("Size of integer is %ld\n", sizeof(int));
    printf("Address p+1 is HEX : %p \t INT : %ld\n", p+1, (long int)(__intptr_t)(p+1));
    
    printf("\n");
    printf("Address p+2 is HEX : %p \t INT : %ld\n", p+2, (long int)(__intptr_t)(p+2));
    // integer takes four bytes, look the difference in address of p, p+1 and p+2
    return 0;
}