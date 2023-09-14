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

    // usign double pointer
    int** arr2 = (int**)malloc(MAX_ROWS*sizeof(int*));

    if(arr2 == NULL){
        printf("Memory allocation failed.\n");
        return 1;
    }

    for(int i=0; i<MAX_ROWS; i++){
        arr2[i] = (int*)malloc(MAX_COLS * sizeof(int));
        if(arr2[i] == NULL){
            printf("Memory allocation failed.\n");
            return 1;
        }
    }

    printf("Elements for %d x %d matrix? \n", MAX_ROWS, MAX_COLS);
    for(int i=0; i< MAX_ROWS; i++){
        printf("For Row %d\n", i);
        for(int j=0; j<MAX_COLS; j++){
            scanf("%d", &arr2[i][j]);
        }
    }

    printf("Elements are, %d x %d matrix: \n", MAX_ROWS, MAX_COLS);
    for(int i=0; i< MAX_ROWS; i++){
        for(int j=0; j<MAX_COLS; j++){
            printf("%d\t", arr2[i][j]);
        }
        printf("\n");
    }

    // free memory
    for(int i=0; i<MAX_ROWS; i++){
        free(arr2[i]);
    }
    free(arr2);

    return 0;
}

// 1D to 2D formula : row_index * MAX_COLS + column_index
// i * MAX_COLS + j