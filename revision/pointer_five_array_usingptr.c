#include<stdio.h>
#include<stdlib.h>
// Create an array using dymanic memory allocation 
#define MAXSIZE 5

int* newArray(){
    int* arr = (int*)malloc(MAXSIZE * sizeof(int));
    if(arr == NULL){
        return NULL;
    }
    return arr;
}

void ArrayInput(int* arr){
    unsigned short i = 0;
    for(i = 0; i < MAXSIZE; i++){
        printf("Element : ");
        scanf("%d", arr); // arr itself is address
        arr++;
    }
}

void ArrayOutput(int* arr){
    unsigned short i = 0;
    printf("The elements are : ");
    for(i=0; i < MAXSIZE; i++){
        printf("%d\t", *(arr+i));
    }
    printf("\n");
}

int main(){
    int* arr = newArray();
    if(arr == NULL){
        printf("Memory allocation failed.");
        return -1;
    }
    ArrayInput(arr);
    ArrayOutput(arr);
    return 0;
}

// Learning arrays with pointers and dynamic memory allocation
