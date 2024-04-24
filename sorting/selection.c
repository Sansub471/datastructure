// Implementation of selection sort algorithm.
#include<stdio.h>
#include"utilities.c"

int* SelectionSort(int* A, unsigned int N){
    unsigned int i,j, iMin;
    int temp;
    for(i=0; i < (N - 1); i++){
        iMin = i; // Assume the position of smallest element
        for(j=i+1; j < N; j++){
            if(A[j] < A[iMin]){
                iMin = j;
            }
        }
        // Smallest in ith iteration found.
        // Swap part
        temp = A[i];
        A[i] = A[iMin];
        A[iMin] = temp;            
    }
    return A;
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

    // Array taken as user input
    unsigned int N = getSize();
    int* A = InputArray(N);
    printf("The given array is : \n");
    PrintArray(A, N);
    printf("\n");

    printf("The sorted array is : \n");
    int* sortedA = SelectionSort(A, N);
    PrintArray(sortedA, N);

}