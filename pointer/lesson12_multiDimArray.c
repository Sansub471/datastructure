#include<stdio.h>
#include<stdlib.h>

int main(){
     int A[5] = {1,2,3,4,5};
     printf("The element is : %d\n\n", *(A+2));

    int B[2][3] = {{4,5,7},{9,13,17}};
    // B[0]; // 1-D array of three integers
    // B[1]; // 1-D array of three integers
    // Generalize : int B[m][n]

    // Error : 
    // int* p = B; 
    // B is int (*)[3] not int* 
    // B is a pointer to 1-D array of 3 integers not pointer to integer
    
    int(*p)[3] = B;
    printf("The address of B          : %p\n", B); // B or &B[0]
    printf("The address of &B[0]      : %p\n\n", &B[0]); // B or &B[0]
    printf("The address of *B         : %p \n", *B);
    printf("The address of B[0]       : %p \n", B[0]);
    printf("The address of &B[0][0]   : %p \n\n", &B[0][0]);

    printf("The value of **B     : %d\n", **B);
    printf("The value of B[0][0] : %d\n\n", B[0][0]);


    printf("The address of p  : %p\n", p); 
    printf("The address of *p : %p\n", *p); 
    printf("The address of **p : %d\n", **p); 

    return 0;
}