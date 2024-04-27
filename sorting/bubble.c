#include<stdio.h>
#include<stdbool.h>

#include"bubble.h"
#include"utilities.c"


void BubbleSort(int* A, unsigned int N){
    int i,j;
    for(i=1; i < N; i++){
        for(j=0; j < N - 1; j++){
            if(A[j] > A[j+1]){
                swap(&A[j], &A[j+1]);
            }
        }
    //printf("Pass : %d\n", i);
    //PrintArray(A, N);
    }
}
// Time complexity : O(n^2)

void OptimizedBubbleSort(int* A, unsigned int N){
    int i,j;
    for(i=0; i< N - 1; i++){
        bool swapped = false;
        for(j=0; j< N - i - 1; j++){
            if(A[j] > A[j+1]){
                swap(&A[j], &A[j+1]);
                swapped = true;
            }
        }
        //printf("Pass : %d\n", i);
        //PrintArray(A, N);

        // if no two elements swapped by inner loop, break
        if(swapped == false) break;
    }
}
// Best case : O(n)
// Average case : O(n^2)
// Worst case : O(n^2)

 int main(){
    // Let's try with the given data
    int A[] = {89, 34, 1, 3, -15, 37, 12, 23, 21, 10};
    unsigned int N = sizeof(A) / sizeof(A[0]);
    printf("The given array is : \n");
    PrintArray(A, N);
    printf("\n");

    BubbleSort(A, N);
    printf("The sorted array is: \n");
    PrintArray(A, N);
    printf("\n");

    int B[] = {89, 34, 1, 3, -15, 37, 12, 23, 21, 10};
    unsigned int size = sizeof(B) / sizeof(B[0]);
    printf("The given array is : \n");
    PrintArray(B, size);
    printf("\n");

    OptimizedBubbleSort(B, size);
    printf("The sorted array is: \n");
    PrintArray(B, size);
    printf("\n");
    return 0;
 }