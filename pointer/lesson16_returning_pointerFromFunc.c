#include<stdio.h>
#include<stdlib.h>

// pointers as function returns
// pointer is just another data type

int* Sum(int a, int b){
    int* s = (int*)malloc(sizeof(int));
    *s = a + b;
    return s;
}

int* Summation(int* a, int* b){
    int c = (*a) + (*b);
    return &c; // Address of the local variable
}
// c is local variable to this function
// function memory is allocated in the stack
// after the function terminates, the memory of c get deallocated
// i.e. the function is poped out of the stack
// hence returning address of local variable is not permissible

// you could allocate memory in heap using pointer like in Sum()
// and return the pointer
// we have to explicitly deallocate memory in heap, but have no control
// over the memory in the stack

int Addition(int* a, int* b){
    int c = (*a) + (*b);
    return c;
}

int Add(int a, int b){
    int c = a + b;
    return c;
}

int main(){
    int a = 12, b = 34;
    int* sum = Sum(a,b);
    int* summation = Summation(&a, &b);
    printf("Sum,       the sum of %d and %d is : %d\n", a, b, *sum);
    printf("Summation, the sum of %d and %d is : %d\n", a, b, *summation);
    printf("Addition,  the sum of %d and %d is : %d\n", a, b, Addition(&a, &b));
    printf("Add,       the sum of %d and %d is : %d\n", a, b, Add(a,b));
    return 0;
}

// The important thing is to understand the usecase
