// why integer strongly typecasted?
#include<stdio.h>
int main(){
    int a = 1025;
    int *p;
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