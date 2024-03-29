#include<stdio.h>
#include<stdlib.h>

#define MAXROW 2
#define MAXCOL 3

// plan : 
// 1. Create an array of int** whose size is the number of ROWS.
// 2. Each element of int** array points to the int* that has space allocated for elements of size COLS.
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

int main(){
    int** arr2d = new2DArray();
    if (arr2d == NULL){
        printf("Memory allocation failed, exiting.");
        return -1;
    }
    
    return 0;
}
