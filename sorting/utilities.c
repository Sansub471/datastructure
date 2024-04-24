#include<stdio.h>
#include<stdlib.h>
#include"utilities.h"

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