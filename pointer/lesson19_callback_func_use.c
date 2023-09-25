// Usecase of call back function
// Why do we need call back function at all?

#include<stdio.h>
#include<stdlib.h>

// Chage return to switch between ascending or descending
int compare(int a, int b){
    if(a > b) return 1;
    else return -1;
}

int absolute_compare(int a, int b){
    if(abs(a) > abs(b)) return 1;
    return -1;
}

// elements to compare are being passed by address
// qsort can sort array of any datatype
// you have to typecast to the proper data type 
int qsortCompare(const void* a, const void* b){
    int A = *((int*)a); // typecasting to int* and getting value
    int B = *((int*)b);
    return A - B; // increasing order
    // try B - A // descending
    // try with abs()
}

// return type must be integer
// void* is generic, can be type casted to any data type
int qsortFloat(const void* a, const void* b){
    float A = *((float*)a);
    float B = *((float*)b);
    return B - A;
    // try A - B
    // try with abs()
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

    int B[] = {-31, 22, -1, 50, -6, 4};
    BubbleSort(B, 6, absolute_compare);
    for(i=0; i<6; i++) printf("%d ", B[i]);
    printf("\n");

    printf("\nQuick sort, integer array : \n");
    qsort(A, 6, sizeof(int), qsortCompare);
    for(i=0; i<6; i++) printf("%d ", A[i]);
    printf("\n");

    qsort(B, 6, sizeof(int), qsortCompare);
    for(i=0; i<6; i++) printf("%d ", B[i]);
    printf("\n\n");

    printf("Quick sort, float array : \n");
    float C[]={23.34, 12.45, 89.56, 45.34, 3.2, 24.78};
    qsort(C, 6, sizeof(float), qsortFloat);
    for(i=0; i<6; i++) printf("%.2f ", C[i]);
    printf("\n\n");

    return 0;
}

// Call back is useful for event handling
// We will see more examples of call back functions.