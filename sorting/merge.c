#include<stdio.h>
#include<stdlib.h>

#include"merge.h"
#include"utilities.c"


void Merge(int* L, int* R, int* A){
    int nL = sizeof(L) / sizeof(L[0]);
    int nR = sizeof(R) / sizeof(R[0]);
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

    // if one of the sub-array exahusts first
    while( i < nL){
        A[k] = L[i];
        i += 1;
        k += 1;
    }

    while( j < nR){
        A[k] = R[j];
        j += 1;
        k += 1;
    }
}

void MergeSort(int* A){
    int N = sizeof(A) / sizeof(A[0]);
    if (N < 2) return;
    int mid = N / 2;
    int* left = (int*)malloc(sizeof(int) * mid);
    int* right = (int*)malloc(sizeof(int) * (N - mid));
    int i = 0;
    for(i=0; i <= mid - 1; i++){
        left[i] = A[i];
    }

    for(i=mid; i <= N - 1; i++){
        right[i] = A[i];
    }
    MergeSort(left);
    MergeSort(right);
    Merge(left, right, A);
    free(left); free(right);
}