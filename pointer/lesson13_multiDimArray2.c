#include<stdio.h>

int main(){
    int C[3][2][2] = {
        {
            {2,5},{7,9}
        },
        {
            {3,4},{6,1}
        },
        {
            {0,8},{11,13}
        }
    };

    int(*p)[2][2] = C;
    printf("The address of C         HEX: %p\t %ld\n", C, (long int)(__intptr_t)C); // int(*)[2][2] pointer
    printf("The address of *C        HEX: %p\t %ld\n", *C, (long int)(__intptr_t)*C); // int(*)[2] pointer
    printf("The address of C[0]      HEX: %p\t %ld\n", C[0], (long int)(__intptr_t)C[0]); // int(*)[2] pointer
    printf("The address of &C[0][0]  HEX: %p\t %ld\n", &C[0][0], (long int)(__intptr_t)&C[0][0]); // int(*)[2] pointer
    printf("The address of **C       HEX: %p\t %ld\n\n", **C, (long int)(__intptr_t)**C); // int(*) pointer

    printf("The value of ***C     : %d\n", ***C);
    return 0;
}