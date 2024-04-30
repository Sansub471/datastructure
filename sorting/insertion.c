#include<stdio.h>
#include"insertion.h"
#include"utilities.c"

void InsertionSort(int* A, unsigned int N){
    int i,j,value,hole;
    for(i=1; i < N; i++){
        value = A[i];
        hole = i;
        while(hole > 0 && A[hole-1] > value){
            {
                A[hole] = A[hole - 1];
                hole--;
            }
        A[hole] = value;
        }
    }
}

int main(){
    // Let's show one example without user input
    int arr[] = {56,12,7,21,67,23,17,9,13};
    unsigned int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("The given array is : \n");
    PrintArray(arr, size);
    printf("\n");

    InsertionSort(arr, size);
    printf("The sorted array is : \n");
    PrintArray(arr, size);
    printf("\n");

    // Let's take user input and sort it.
    unsigned int N = getSize();
    int* A = InputArray(N);
    printf("The given array is : \n");
    PrintArray(A, N);
    printf("\n");

    InsertionSort(A, N);
    printf("The sorted array is : \n");
    PrintArray(A,N);
    printf("\n");
    return 0;
}

// I'm wasting my time and life for nothing.