// Implementation of selection sort algorithm.
#include<stdio.h>
#include"utilities.c"

int* SelectionSort(int* A, unsigned int N){
    unsigned int i,j, iMin;
    int temp;
    for(i=0; i< N - 1; i++){
        iMin = i; // Assume the position of smallest element
        for(j=i+1; j < N; j++){
            if(A[j] > A[iMin]){
                iMin = j;
            }
            // Swap part
            temp = A[i];
            A[i] = A[iMin];
            A[iMin] = temp;            
        }
    }
    return A;
}

int main(){
    unsigned int N = getSize();
    int* A = InputArray(N);
    PrintArray(A, N);

    printf("The sorted array is : ");
    PrintArray(SelectionSort(A, N), N);
}