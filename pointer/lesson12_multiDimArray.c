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
    printf("The address of B        HEX: %p\t %ld\n", B, (long int)(__intptr_t)B); // B or &B[0]
    printf("The address of &B[0]    HEX: %p\t %ld\n\n", &B[0], (long int)(__intptr_t)&B[0]); // B or &B[0]
    printf("The address of *B       HEX: %p \t %ld\n", *B, (long int)(__intptr_t)*B);
    printf("The address of B[0]     HEX: %p \t %ld\n", B[0],(long int)(__intptr_t)B[0]);
    printf("The address of &B[0][0] HEX: %p \t %ld\n\n", &B[0][0],(long int)(__intptr_t)&B[0][0]);

    printf("The value of **B     : %d\n", **B);
    printf("The value of B[0][0] : %d\n\n", B[0][0]);

    printf("The address of B         HEX: %p\t %ld\n", B, (long int)(__intptr_t)B); // pointer to B[0] array, int(*)[3]
    printf("The address of B + 1     HEX: %p\t %ld\n", (B+1),(long int)(__intptr_t)(B+1)); // pointer to B[1] array, int(*)[3]
    printf("The address of *(B + 1)  HEX: %p\t %ld\n\n", *(B+1),(long int)(__intptr_t)*(B+1)); // pointer to first element of B[1] array, int*

     printf("The value of **(B + 1)    : %d\n\n", **(B+1));


    //int (*q) = B+1; // B+1 is also int(*q)[3]
    int* r = *(B+1); // this works because *(B+1) is int* pointer

    printf("The address of B      HEX: %p\t %ld\n", B, (long int)(__intptr_t)B); // pointer to B[0] array, int(*)[3]
    printf("The address of *B     HEX: %p \t %ld\n\n", *B, (long int)(__intptr_t)*B); // pointer to 1st element of B[0] array, int* type

    printf("The value of **B     : %d\n\n", **B);

    printf("The address of *B + 1 HEX: %p\t %ld\n", (*B+1), (long int)(__intptr_t)(*B+1));
    printf("The value of *(*B+1)     : %d\n\n", *(*B+1));

    int* s = *B; // *B is pointer to first element of B[0] array, type int*
    int* t = *B + 1;
    
    printf("The address of p   HEX: %p\t %ld\n", p,(long int)(__intptr_t)p); 
    printf("The address of *p  HEX: %p\t %ld\n", *p,(long int)(__intptr_t)*p); 
    printf("The address of **p HEX: %d\t %ld\n", **p,(long int)(__intptr_t)**p); 

    return 0;
}