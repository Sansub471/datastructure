#include<stdio.h>
#include<stdlib.h>

#define MAX_ROWS 2
#define MAX_COLS 3

int OneDimArray(int A[]){
    // int A[] is seen as int* by the compiler
    return *(A+1); // just random

}

int TwoDimArray(int B[][3]){
    // only first dimension is allowed to left empty
    // the compiler interprets B[][2] as int(*B)[3]
    return *(*B + 1);
}


int ThreeDimArray(int C[][2][2]){
    // only first dimension is allowed to leave empty
    // the compiler interprets as int(*C)[2][2]
    return ***C;
}

int** Array2DdoublePointer(){
 // usign double pointer
    int** arr2 = (int**)malloc(MAX_ROWS*sizeof(int*));

    if(arr2 == NULL){
        printf("Memory allocation failed.\n");
        return NULL;
    }

    for(int i=0; i<MAX_ROWS; i++){
        arr2[i] = (int*)malloc(MAX_COLS * sizeof(int));
        if(arr2[i] == NULL){
            printf("Memory allocation failed.\n");
            return NULL;
        }
    }

    printf("Elements for %d x %d matrix? \n", MAX_ROWS, MAX_COLS);
    for(int i=0; i< MAX_ROWS; i++){
        printf("For Row %d\n", i);
        for(int j=0; j<MAX_COLS; j++){
            scanf("%d", &arr2[i][j]);
        }
    }
    return arr2;
}

void Array2DdoublePointerPrint(int** arr2){
    printf("Elements are, %d x %d matrix: \n", MAX_ROWS, MAX_COLS);
    for(int i=0; i< MAX_ROWS; i++){
        for(int j=0; j<MAX_COLS; j++){
            printf("%d\t", arr2[i][j]);
        }
        printf("\n");
    }
}

void FreeMemory(int** arr2){
    // free memory
    for(int i=0; i<MAX_ROWS; i++){
        free(arr2[i]);
    }
    free(arr2);
}

int main(){
    int A[5] = {1,2,3,4,5};
    int B[2][3] = {{4,5,7},{9,13,17}};
        int C[3][2][2] = {
        {
            {2,5},{7,9}
        },
        {
            {3,4},{6,1}
        },
        {
            {0,8},{11,13}
        }
    };
    printf("OneDimArray Function   : %d\n", OneDimArray(A));
    printf("TwoDimArray Function   : %d\n", TwoDimArray(B));
    printf("ThreeDimArray Function : %d\n", ThreeDimArray(C));

    // Let's try using int** for 2-D array just for fun
    int** arr2 = Array2DdoublePointer();
    if (arr2 == NULL){
        printf("Memory allocation failed inside function.");
        return -1;
    }
    Array2DdoublePointerPrint(arr2);
    FreeMemory(arr2);
    return 0;
}
// Mistake : people try to use int** for two dimensional array
// Mistake : people try to use int*** for three dimensional array

// Using int** for 2-D array worked, shouldn't I use it? 
// It is just one way of implementing 2-D array
// The goal here is understand pointers, not focus of multiple possiblities of impelementation
