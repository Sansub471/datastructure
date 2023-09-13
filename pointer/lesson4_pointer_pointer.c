// pointer to pointer concept
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE  1
int main(){
    int* arr = malloc(MAXSIZE * sizeof(int));
    int* arr_ptr = arr; // keep track of the head
    if (arr == NULL){
        printf("Memory allocation failed.");
        return -1;
    }
    printf("Give me %d numbers : \n", MAXSIZE);
    for (int i=0; i< MAXSIZE; i++){
        scanf("%d", arr);
        arr++;
    }

    // resetting the head pointer
    arr = arr_ptr;
    printf("The numbers entered are : \n");
    for (int i=0; i< MAXSIZE; i++){
        printf("%d \t", *arr);
        arr++;
    }
    printf("\n");
    free(arr_ptr); // free the memory to prevent memory leak

    printf("\n");
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