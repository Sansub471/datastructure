#include<stdio.h>
#include<stdlib.h>

int main(){

    int a; // goes on stack
    int* p;
    p = (int*)malloc(sizeof(int));
    *p = 77;

    // after memory used, clear it using free()
    free(p);

    p = (int*)malloc(sizeof(int));
    *p = 23;

    int* arr = (int*)malloc(10*sizeof(int));
    // memory for 10 integers array
    // contagious memory
    
    // malloc return NULL if memory allocation failed.

    // in C++
    // arr = new int[10];
    // delete[] arr;

    return 0;
}