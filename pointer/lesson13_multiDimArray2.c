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

    int(*q)[2] = C[0]; // pointer to 2-D array of size 2x2
    // *q is pointer to first element of first 1-D array pointed by q
    // Here, pointer to array {2,5}

    int(*r)[2] = C[1]; // pointer to 2-D array of size 2x2
    int(*s)[2] = C[2]; // pointer to 2-D array of size 2x2

    printf("The value of **q     : %d\n\n", **q);

    int* t = C[0][0];
    printf("The 3-D array is : \n");
    for(int i=0; i<3; i++){
        for(int j=0; j<2; j++){
            for(int k=0; k<2; k++){
                printf("%d\t", *(*(*(C + i) + j) + k));
                // C[i][j][k] = *(C[i][j] + k)
                //            = *(*(C[i] + j) + k)
                //            = *(*(*(C + i) + j) + k)
            }
            printf("|");
        }
        printf("\n");
    }

    

    return 0;
}