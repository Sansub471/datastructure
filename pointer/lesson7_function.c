// pointers as function arguments - call by reference
#include<stdio.h>
#include<stdio.h>

void increment(int* a){
    (*a)++; // *a = (*a) + 1;
}

int* Increment(int* a){
    (*a)++;
    return a;
}
int main(){
    int a = 77;
    printf("The value of 'a' is : %d\n", a);
    increment(&a);
    printf("The new value of 'a' is : %d\n", a);

    int* b = Increment(&a);
    printf("The new value of 'a' returned pointer is : %d\n", *b);
    return 0;
}