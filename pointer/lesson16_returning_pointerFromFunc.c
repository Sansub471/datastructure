#include<stdio.h>
#include<stdlib.h>

int* Sum(int a, int b){
    int* s = (int*)malloc(sizeof(int));
    *s = a + b;
    return s;
}

int main(){
    int a = 12, b = 34;
    int* sum = Sum(a,b);
    printf("The sum of %d and %d is : %d\n", a, b, *sum);
    return 0;
}