#include<stdio.h>
#define MAX 10

int* bubbleSort(int* A, int N){
    for(int i=0; i < N; i++){
        for(int j=i; j < N; j++){
            if (A[i] > A[j]){
                // swap
                A[i] = A[i] + A[j];
                A[j] = A[i] - A[j];
                A[i] = A[i] - A[j];
            }
        }
    }
    return A;
}

void Print(int* A){
    printf("The array is : ");
    for (int i=0; i < MAX; i++){
        printf("%d\t", A[i]);
    }
    printf("\n");

}

 int main(){
    int A[10] = {89, 34, 1, 3, -15, 37, 12, 23, 21, 10};
    Print(A);
    int* B = bubbleSort(A, MAX);
    Print(B);    
    return 0;
 }
 // This is the name of sorting game