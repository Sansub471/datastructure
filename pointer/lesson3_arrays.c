// why integer strongly typecasted?
#include<stdio.h>
int main(){
    int a = 1025;
    int *p;
    p= &a;
    printf("Size of integer is %lu bytes \n", sizeof(int));
    printf("Address = %ld, value  = %d\n", (long int)(__intptr_t)p, *p);
    return 0;
}