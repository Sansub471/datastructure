#include<stdio.h>
#include<stdlib.h>

#include"merge.h"
#include"utilities.c"

// int* L : left sub array
// int* R : right sub array
// int* A : original array
// unsigned nL : length(L)
// unsigned nR : length(R)
void Merge(int* L, unsigned nL, int* R, unsigned nR, int* A){
    int i=0,j=0,k=0;
    while(i < nL && j < nR){
        if(L[i] <= R[j]){
            A[k] = L[i];
            i += 1;
        }
        else{
            A[k] = R[j];
            j += 1;
        }
        k += 1;
    }

    // if one of the sub-array exahusts first, only one of the while will be executed.
    while( i < nL){
        A[k] = L[i];
        i += 1;  k += 1;
    }

    while( j < nR){
        A[k] = R[j];
        j += 1;   k += 1;
    }
}

void MergeSort(int* A, unsigned int N){
    if (N < 2) return;
    unsigned int mid = N / 2;
    int* left  = (int*)malloc(sizeof(int) * mid);
    int* right = (int*)malloc(sizeof(int) * (N - mid));

    //if (left == NULL || right == NULL) return;
    int i = 0;
    for(i=0; i <= mid - 1; i++){
        left[i] = A[i];}

    for(i=mid; i <= N - 1; i++){
        right[i-mid] = A[i];}
    
    MergeSort(left, mid);
    MergeSort(right, N - mid);
    Merge(left, mid, right, N - mid, A);
    free(left); free(right);
}

int main(){
    // Let's try with an array
    int A[] = {2,4,1,6,8,5,3,7};
    unsigned int N = sizeof(A) / sizeof(A[0]);
    printf("The given array to sort is : \n");
    PrintArray(A, N);
    printf("\n");

    MergeSort(A, N);
    printf("The sorted array is : \n");
    PrintArray(A, N);
    printf("\n");

    /*
    // let's try with user input
    unsigned size  = getSize();
    int* arr = InputArray(size);
    printf("The given array to sort is : \n");
    PrintArray(arr, size);
    printf("\n");

    MergeSort(arr, size);
    printf("The sorted array is : \n");
    PrintArray(arr, size);
    printf("\n");
    */

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

    MergeSort(array, sizeN);
    printf("The sorted random array is : \n");
    PrintArray(array, sizeN);
    printf("\n");


    return 0;
}


// Back to the game.