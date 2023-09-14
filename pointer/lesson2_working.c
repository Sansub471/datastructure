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
    printf("Can access memory location using pointer arithematic!\n");

    // lesson 2
    a = 1025;
    p= &a;
    printf("Size of integer is %lu bytes \n", sizeof(int));
    printf("Address = %ld, value  = %d\n", (long int)(__intptr_t)p, *p);
    printf("Address = %ld, value  = %d\n", (long int)(__intptr_t)(p+1), *(p+1));

    char* p0;
    p0 = (char*)p; // typecasting
    printf("Size of char is %lu bytes \n", sizeof(char));
    printf("Address = %ld, value  = %d\n", (long int)(__intptr_t)p0, *p0);
    // p is now typecasted to char pointer, hence it only accesses one byte
    // of memory
    // 1025 = 00000000 00000000 00000100 00000001
    printf("Address = %ld, value  = %d\n", (long int)(__intptr_t)(p0+1), *(p0+1));

    // generic pointer type
    void* p1;
    p1 = p;
    

    return 0;
}