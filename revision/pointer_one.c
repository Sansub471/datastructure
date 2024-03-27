#include<stdio.h>
int main(){
    // Let's try with pointers.
    float varone = 34.343;
    float* ptrone = &varone;

    printf("The address of varone is : %p\n", &varone);
    printf("The value  of  varone is : %.3f\n", varone);

    varone = 77.17;
    printf("The address of ptrone is : %p\n", &ptrone);
    printf("The value  of  ptrone is : %.3f\n", *ptrone);

    float** ptrdouble = &ptrone;
    printf("The address of ptrdouble is : %p\n", &ptrdouble);
    printf("The value of *ptrdouble is &ptrone : %p\n", *ptrdouble);
    printf("The value of **ptrdouble is varone or *ptrone : %.3f\n", **ptrdouble);

    // You can try with triple pointer too.

    float*** ptrtriple = &ptrdouble;
    float**** ptrquadra = &ptrtriple;
    printf("The value of ****ptrquadra is : %.3f\n", ****ptrquadra);

    // perhaps we can have even higher pointer, but who is gonna try?? lol

    char* name = "Is this even allowed in C?";
    printf("The string pointer in C : %s\n", name);

    return 0;
}