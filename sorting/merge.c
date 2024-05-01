#include<stdio.h>
#include"merge.h"


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