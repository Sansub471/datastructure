// 2D array using int* pointer
#include<stdio.h>
#include<stdlib.h>

#define MAX_ROWS 2
#define MAX_COLS 3
int main(){
    int* arr =(int*)malloc(MAX_COLS * MAX_ROWS * sizeof(int));
    int* arr_ptr = arr;

    printf("Elements for %d x %d matrix? \n", MAX_ROWS, MAX_COLS);
    for(int i=0; i< MAX_ROWS; i++){
        printf("For Row %d\n", i);
        for(int j=0; j<MAX_COLS; j++){
            scanf("%d", arr);
            arr++;
        }
    }

    arr = arr_ptr; // resetting the header pointer.
    printf("Elements are, %d x %d matrix: \n", MAX_ROWS, MAX_COLS);
    for(int i=0; i< MAX_ROWS; i++){
        for(int j=0; j<MAX_COLS; j++){
            printf("%d\t", *arr);
            arr++;
        }
        printf("\n");
    }

    free(arr_ptr);
    return 0;
}

// 1D to 2D formula : row_index * MAX_COLS + column_index
// i * MAX_COLS + j