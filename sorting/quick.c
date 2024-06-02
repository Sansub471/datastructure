#include<stdio.h>

#include"utilities.c"
#include"quick.h"

// keeping smaller elements to the left of pivot
int Partition(int* A, int start, int end){
    int pivot = A[end]; // pivot be the last element
    int pIndex = start; // set partition index as start initially
    int i;

    // Goal : push elements lesser than pivot to the left of pivot
    for(i=start; i <= end - 1 ; i++){
        if(A[i] <= pivot){
            swap(&A[i], &A[pIndex]); // swap if element is lesser than pivot
            pIndex++;
        }
    }
    swap(&A[pIndex], &A[end]); // swap pivot with element at partition index
    return pIndex;
}


void QuickSort(int* A, int start, int end){
    if (start >= end ) return ; // if(start < end ) { put code here}
    int pIndex = Partition(A, start, end);
    QuickSort(A, start, pIndex - 1);
    QuickSort(A, pIndex + 1, end);
}

int main(){
    // Let's try with an array
    int A[] = {2,4,1,6,8,5,3,7};
    unsigned int N = sizeof(A) / sizeof(A[0]);
    int start = 0, end = N -1;
    printf("The given array to sort is : \n");
    PrintArray(A, N);
    printf("\n");

    QuickSort(A, start, end);
    printf("The sorted array is : \n");
    PrintArray(A, N);
    printf("\n");
    

    // Let's try with randomly created array of given size
    unsigned sizeN = getSize();
    int* array = randomArray(sizeN);
    if(array == NULL){
        printf("Memory allocation failed!");
        return 0;
    }

    printf("The random array is : \n");
    PrintArray(array, sizeN);
    printf("\n");

    QuickSort(array, 0, sizeN - 1);
    printf("The sorted random array is : \n");
    PrintArray(array, sizeN);
    printf("\n");

    return 0;
}