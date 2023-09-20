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


    // memory for 10 integers array
    // contagious memory
    
    // malloc return NULL if memory allocation failed.

    // in C++
    // arr = new int[10];
    // delete[] arr;

    // Lesson 2
    // Functions to allocate a block of memory in C

    // malloc - void* malloc(size_t size)
    // size_t is unsigned int
    // size in bytes

    // calloc - void* calloc(size_t num, size_t size)
    int* ptr = (int*)calloc(3, sizeof(int));

    // malloc vs calloc
    // malloc doens't intialize the bytes with any values, they have garbage
    // calloc initializes the bytes with zero value

    // realloc - void* realloc(void* ptr, size_t size)

    // example of malloc
    int n;
    printf("Enter the size of an array : ");
    scanf("%d", &n);
    int* arr = (int*)malloc(n*sizeof(int));
    int* arr_ptr = arr; // keep track of start here

    for(int i=0; i<n; i++){
        //arr[i] = i+1;
        *(arr + i) = i+1;
    }

    for(int i= 0; i<n; i++){
        printf("%d ", *arr); // arr[i]
        arr++;
    }
    printf("\n");
    return 0;
}