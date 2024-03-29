#include<stdio.h>
#include<stdlib.h>

#define MAXROW 2
#define MAXCOL 3

// plan : 
// 1. Create an array of int** whose size is the number of ROWS.
// 2. Each element of int** array points to the int* that has space allocated for elements of size COLS.

// The caller must free the memory to prevent leak
int** new2DArray(){
    int** rows = (int**)malloc( MAXROW * sizeof(int*));
    if (rows == NULL){return NULL;}

    unsigned short i;
    for(i = 0; i<MAXROW; i++){
        rows[i] = (int*)malloc( MAXCOL * sizeof(int));
        if(rows[i] == NULL){
            return NULL;
        }
    }
    return rows;   
}

void TwoDArrayInput(int** arr){
    printf("Elements for %d x %d matrix? \n", MAXROW, MAXCOL);
    unsigned short i,j;
    for(i=0; i < MAXROW; i++){
        printf("Elements of Row %d : \n", i);
        for(j=0; j < MAXCOL; j++){
            printf("Element [%d][%d] : ", i, j);
            scanf("%d", *(arr+i) + j ); // or *(arr+i)+j &arr[i][j]
        }
        printf("\n");
    }
}

void TwoDArrayOutput(int** arr){
    printf("Elements for %d x %d matrix? \n", MAXROW, MAXCOL);
    unsigned short i,j;
    for(i=0; i < MAXROW; i++){
        for(j=0; j < MAXCOL; j++){
            printf("%d\t", *(*(arr+i)+j)); // or *(*(arr+i)+j) or arr[i][j]
            
        }
        printf("\n");
    }
}

int main(){
    // Make sure to free the memory correctly.
    int** arr2d = new2DArray();

    printf("The size of arr2d : %ld \n", sizeof(arr2d));
    if (arr2d == NULL){
        printf("Memory allocation failed, exiting.");
        return -1;
    }

    TwoDArrayInput(arr2d);
    TwoDArrayOutput(arr2d);

    // At last free the allocated memory
    unsigned short i = 0;
    for(i=0; i < MAXROW; i++){
        free(arr2d[i]);
    }
    free(arr2d);
    return 0;
}
