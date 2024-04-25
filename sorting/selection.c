// Implementation of selection sort algorithm.
#include<stdio.h>

#include"selection.h"
#include"utilities.c"

int* SelectionSort(int* A, unsigned int N){
    unsigned int i,j;
    for(i=0; i < (N - 1); i++){ // need to do n - 2 passes
        int iMin = i; // elements from i till n - 1 are candidates
        for(j=i+1; j < N; j++){
            if(A[j] < A[iMin]){
                iMin = j; // update the index of minimun element
            }
        }
        // Smallest in ith iteration found.
        // Swap part
        swap(&A[i], &A[iMin]);         
    }
    return A;
}

// Even void return type would work, array is passed by reference in C
void SelectionSortN(int A[], unsigned int N){
    unsigned int i,j;
    for(i=0; i < (N - 1); i++){ // need to do n - 2 passes
        int iMin = i; // elements from i till n - 1 are candidates
        for(j=i+1; j < N; j++){
            if(A[j] < A[iMin]){
                iMin = j; // update the index of minimun element
            }
        }
        // Smallest in ith iteration found.
        // Swap part
        int temp = A[i];
        A[i] = A[iMin];
        A[iMin] = temp;            
    }
}

int main(){

    // Let's show one example without user input
    int arr[] = {56,12,7,21,67,23,17,9,13};
    unsigned int size = sizeof(arr) / sizeof(arr[0]);
    printf("The given array is : \n");
    PrintArray(arr, size);
    printf("\n");

    printf("The sorted array is : \n");
    int* sortedArr = SelectionSort(arr, size);
    PrintArray(sortedArr, size);

    printf("The original array is also sorted : \n");
    PrintArray(arr, size); // original arr is also sorted

    // Array taken as user input
    unsigned int N = getSize();
    int* A = InputArray(N);
    printf("The given array is : \n");
    PrintArray(A, N);
    printf("\n");

    //printf("The sorted array is : \n");
    //int* sortedA = SelectionSort(A, N);
    //PrintArray(sortedA, N);

    printf("The sorted array is :  \n");
    SelectionSortN(A, N);
    PrintArray(A, N);

}

// Time complexity : O(n^2)