#include<stdio.h>
#include<stdlib.h>

void swap(float* first, float* second){
    float temp;
    temp = *first;
    *first = *second;
    *second = temp;
}

int main(){
    float one, two;
    one = 45.89; two = 89.45;
    swap(&one, &two);
    printf("The first : %.2f \n", one);
    printf("The second : %.2f\n", two);

    return 0;
}