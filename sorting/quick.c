#include<stdio.h>

#include"utilities.c"
#include"quick.h"

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
    
    return 0;
}
