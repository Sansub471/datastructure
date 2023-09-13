// pointer to pointer concept
#include<stdio.h>
#include<stdlib.h>
int main(){

    // pointer to pointers
    int x = 17;
    int* p = &x;
    *p = 77;
    int** q = &p; // store address of p
    int*** r = &q; // store address of q

    printf("The value of *p is : %d\n", *p);
    printf("The value of x  is : %d\n", x);
    printf("\n");

    printf("The address of x,   HEX: %p \t %ld\n", &x, (long int)(__intptr_t)&x);
    printf("The address in p,   HEX: %p \t %ld\n", p, (long int)(__intptr_t)p);
    printf("The address of p,   HEX: %p \t %ld\n", &p, (long int)(__intptr_t)&p);
    printf("\n");

    printf("The address in q,   HEX: %p \t %ld\n", q, (long int)(__intptr_t)q);
    printf("The address of q,   HEX: %p \t %ld\n", &q, (long int)(__intptr_t)&q);
    printf("The address in *q,  HEX: %p \t %ld\n", *q, (long int)(__intptr_t)*q);
    printf("\n");

    printf("The address in r,   HEX: %p \t %ld\n", r, (long int)(__intptr_t)r);
    printf("The address of r,   HEX: %p \t %ld\n", &r, (long int)(__intptr_t)&r);
    printf("The address in *r,  HEX: %p \t %ld\n", *r, (long int)(__intptr_t)*r);
    printf("The address in **r, HEX: %p \t %ld\n", **r, (long int)(__intptr_t)**r);
    printf("\n");

    printf("The value  of **q is : %d\n", *(*q)); // **q
    printf("The value of ***r is : %d\n", *(*(*r))); // ***r
    // brackets to avoid precedence confusion
    return 0;
}