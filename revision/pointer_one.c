#include<stdio.h>
int main(){
    // Let's try with pointers.
    float varone = 34.343;
    float* ptrone = &varone;

    printf("The address of varone is : %p\n", &varone);
    printf("The value of varone is : %.3f\n", varone);

    varone = 77.17;
    printf("The value of varone is : %.3f\n", *ptrone);

    return 0;
}