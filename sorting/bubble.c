#include<stdio.h>

#include"utilities.c"

void BubbleSort(int* A, unsigned int N){
    int i,j;
    for(i=1; i < N; i++){
        for(j=0; j < N - 1; j++){
            if(A[j] > A[j+1]){
                swap(&A[j], &A[j+1]);
            }
        }
    }
}
// Time complexity : O(n^2)

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
    return 0;
 }