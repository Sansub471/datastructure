// Usecase of call back function
// Why do we need call back function at all?

#include<stdio.h>

// Chage return to switch between ascending or descending
int compare(int a, int b){
    if(a > b) return 1;
    else return -1;
}

void BubbleSort(int* A, int n, int (*compare)(int,int)){
    int i,j,temp;
    for(i=0; i<n; i++){
        for(j=0; j<n-i-1; j++){
            if(compare(A[j], A[j+1]) > 0 ){
                // compare A[j] with A[j+1], ascending
                // for descending A[j] < A[j+1]
                // for such small difference writing new function
                // makes no sense.
                // so we can use callback function here, all sorting
                // methods have some sort of comparision operation
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}

int main(){
    int i, A[] = {3,2,1,5,6,4};
    BubbleSort(A, 6, compare);
    for(i=0; i<6; i++) printf("%d ", A[i]);
    printf("\n");
    return 0;
}
