#include<stdio.h>
// Create an array using dymanic memory allocation 
#define MAXSIZE 5

int main(){
    int* arr = (int*)(malloc(MAXSIZE * sizeof(int)));
    if(arr == NULL){
        printf("Memory allocation failed.");
        return -1;
    }
    int* arrptr = arr; // keep track of head 
    return 0;
}