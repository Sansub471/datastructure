#include<stdio.h>

int SumOfElements(int A[], int size)
{
    printf("Function : ");
    //printf("The size of A : %ld \t size of A[0] : %ld\n", sizeof(A), sizeof(A[0]));
    // sizeof(A) will give size of int* to the array not the entire array
    // This is how compiler interpretes it
    int i, sum = 0;
    for(i=0; i<size; i++){
        sum += A[i];
    }
    return sum;
}

int main(){
    int A[] = {1,2,3,4,5};
    int size = sizeof(A)/sizeof(A[0]);
    int total = SumOfElements(A, size);
    printf("The sum of elements : %d\n", total);
    
    printf("The size of A : %ld \t size of A[0] : %ld\n", sizeof(A), sizeof(A[0]));
    return 0;
}