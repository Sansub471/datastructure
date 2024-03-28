#include<stdio.h>
int main(){
    int A[] = {8, 29, 34, 58, 50, 92, 82};
    int* arrptr = A;

    printf("The address of  A, HEX : %p \t INT: %ld\n", A, (long int)(__intptr_t)A);
    printf("The address of &A, HEX : %p \t INT: %ld\n", &A, (long int)(__intptr_t)&A);

    // A is the address of first element of the array, or &A[i] is address
    // A[i] is the value or *(A + i)

    short SIZE = sizeof(A) / sizeof(int); int i = 0;
    for(i = 0; i < SIZE; i++){
        printf("The address of A+i,   HEX: %p \t INT: %ld\n", A + i, (long int)(__intptr_t)(A+i));
        printf("The address of &A[i], HEX: %p \t INT: %ld\n", &A[i], (long int)(__intptr_t)&A[i]);
        printf("\n");

        printf("The value of  A[i] : %d\n", A[i]);
        printf("The value of *(A+i): %d\n", *(A + i));
        printf("\n");
    }
}