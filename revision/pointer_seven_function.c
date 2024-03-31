#include<stdio.h>
#include<stdlib.h>

void swap(float* first, float* second){
    float temp;
    temp = *first;
    *first = *second;
    *second = temp;
}

void increment(int* a){
    (*a)++; // *a = *(a) + 1
}

int* Increment(int* a){
    (*a)++;
    int* b = (int*)malloc(sizeof(int));
    *b = *a;
    // the value of a is copied to the memory allocated for b
    // b = a means b also points to memory pointed by a
    // There is memory leak, dynamic memory allocated to b is now inaccesible
    // it can neither be freed or deallocated.
    return b;
}

int main(){
    float one, two;
    one = 45.89; two = 89.45;
    swap(&one, &two);
    printf("The first : %.2f \n", one);
    printf("The second : %.2f\n", two);

    int a = 16;
    increment(&a);
    printf("The value of a = %d\n", a);

    int* b = Increment(&a);
    printf("The valued of b = %d\n", *b);
    return 0;
}
// Address of local varible can't be returned.
// Return the dynamically allocated variable only.
