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
    //int* ptr = (int*)calloc(3, sizeof(int));

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
        printf("%d ", *arr_ptr); // arr[i]
        arr_ptr++;
    }
    printf("\n");

    // let's deallocate memory for arr
    free(arr); 
    // memory block pointed by arr* is now availabe for new allocation
    arr = NULL; // After free, adjust pointer to NULL
    // eventhough memory is freed, arr still has address of the memory block
    // it can be exploited later 

    // example using calloc
    int* arr2 = (int*)calloc(n, sizeof(int));
    int* arr2_ptr = arr2; // keep track of head

     for(int i=0; i<n; i++){
        //arr[i] = i+1;
        *(arr2 + i) = i+2;
    }
    for(int i= 0; i<n; i++){
        printf("%d ", *arr2_ptr); // arr[i]
        arr2_ptr++;
    }
    printf("\n");

    int* arr3 = (int*)realloc(arr2, 2*n*sizeof(int));
    // how it works
    // memory size can be increased or decreased

    // if the size of the new block is greater than previous
    // block, and it is possible to extend the previous block
    // i.e. find continuous memory block to it, then previous block is extented

    // otherwise, previous block is copied to the new location
    printf("Previous address, arr2 : %ld \t New address, arr3 : %ld\n", (long int)(__intptr_t)arr2, (long int)(__intptr_t)arr3);
    return 0;
}

// malloc should have random value and calloc zero
// but both had zero on my machine