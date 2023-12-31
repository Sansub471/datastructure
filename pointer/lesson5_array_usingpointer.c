#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE  10

int main(){
    int* arr = (int*)malloc(MAXSIZE * sizeof(int));
    int* arr_ptr = arr; // keep track of the head
    if (arr == NULL){
        printf("Memory allocation failed.");
        return -1;
    }
    printf("Give me %d numbers : \n", MAXSIZE);
    for (int i=0; i< MAXSIZE; i++){
        scanf("%d", arr);
        arr++;
    }

    // resetting the head pointer
    arr = arr_ptr;
    printf("The numbers entered are : \n");
    for (int i=0; i< MAXSIZE; i++){
        printf("%d \t", *arr);
        arr++;
    }
    printf("\n");
    free(arr_ptr); // free the memory to prevent memory leak

    printf("\n");
    return 0;
}