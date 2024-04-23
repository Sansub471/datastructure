// Implementation of selection sort algorithm.
#include<stdio.h>
#include<stdlib.h>

int* inputArray(){
    unsigned int size;
    printf("Give the maxsize of array : ");
    scanf("%d", &size);
    
    // Allocate memory for array and get the input
    int* A = (int*)malloc(sizeof(int) * size);
    if (A == NULL){
        printf("Memory allocation of array failed!");
        return NULL;
    }
    int* head = A;
    unsigned int i = 0;
    for(i=0; i < size; i++){
        printf("Element [%d] : ", i);
        scanf("%d", A);
        A++;
    }
    return A;
}

int main(){

}