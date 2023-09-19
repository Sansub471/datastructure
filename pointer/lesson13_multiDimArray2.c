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
    printf("The address of C         HEX: %p\t %ld\n", C, (long int)(__intptr_t)C);
    printf("The address of *C        HEX: %p\t %ld\n", B, (long int)(__intptr_t)B);
    return 0;
}