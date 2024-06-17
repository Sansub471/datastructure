#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include"utilities.h"

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

unsigned int getSize(){
    unsigned int size;
    printf("Give the maxsize of array : ");
    scanf("%d", &size);
    
    return size;
}

// Function to read array from the user
int* InputArray(unsigned int size){    
    // Allocate memory for array and get the input
    int* A = (int*)malloc(sizeof(int) * size);
    if (A == NULL){
        printf("Memory allocation of array failed!");
        return NULL;
    }
    int* head = A;
    unsigned int i = 0;
    for(i=0; i < size; i++){
        printf("Element [%d] : ", i);
        scanf("%d", A);
        A++;
    }
    return head;
}

// Function to print the given array 
void PrintArray(int* A, unsigned int N){
    if(A == NULL){
        printf("Can't print NULL array!\n");
        return;
    }
    printf("The elements are : ");
    unsigned int i;
    for(i=0; i<N; i++){
        printf("%d \t", *A);
        A++;
    }
    printf("\n");
}

// Get an array with random values
int* randomArray(int size) {
    int* array = (int*)malloc(size * sizeof(int));
    if (array == NULL) {
        return NULL; // memory allocation failed
    }

    // Seed the random number generator
    srand(time(NULL));

    // Fill the array with random integers between 1 and 1000
    for (int i = 0; i < size; i++) {
        array[i] = (rand() % 1000) + 1;
    }
    return array;
}

// Get a random integer between the given integers
int Random(int lower, int upper){
    if(lower > upper){
        swap(&lower, &upper);
    }

    // Seed the random number generator
    srand(time(NULL));
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}
