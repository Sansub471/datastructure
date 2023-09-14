// Some basics of arrays
#include<stdio.h>
int main(){
    int A[] = {34, 45, 99, 12, 90};
    int* ptr = A;
    printf("The Address of A, HEX : %p \t INT : %ld\n", A, (long int)(__intptr_t)A);
    printf("The Address of A, HEX : %p \t INT : %ld\n", &A, (long int)(__intptr_t)&A);
    printf("\n");

    for(int i=0; i<5; i++){
        printf("The Address of (A+i), HEX : %p \t INT : %ld\n", (A+i), (long int)(__intptr_t)(A+i));
        printf("The Address of &A[i], HEX : %p \t INT : %ld\n", &A[i], (long int)(__intptr_t)&A[i]);
        printf("\n");
        printf("The Value of  A[i] : %d\n", A[i]);
        printf("The Value of *(A+i): %d \n", *(A+i));
        printf("\n");
    }
    return 0;
}