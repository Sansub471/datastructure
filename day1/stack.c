//Array based implementation of stack.
#include<stdio.h>
#define MAX_SIZE 101
int A[MAX_SIZE];
int top = -1;

void Push(int x){
    if(top == MAX_SIZE -1){
        printf("Error: stack overflow.\n");

    }
    A[++top] = x; //pre-increment operator
    //Increment will happend before assignment.
}

void Pop(){
    if (top == -1){
        printf("Error: No element to pop\n");
        return ;
    }
    top--;
}

int Top(){
    if (top == -1){
        printf("Empty stack.\n");
    }
    else{
        return A[top];
    }
}

//To verify the operations are happening correctly
void Print(){
    int i;
    printf("Stack : ");
    for(i=top; i>-1; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}
int main(){
    Push(2); Print();
    printf("Top of stack is : %d\n", Top());
    Push(5); Print();
    Push(7); Print();
    Push(8); Print();
    Push(10); Print();
    printf("Top of stack is : %d\n", Top());

    printf("Popping operation.\n");
    Pop(); Print();
    printf("Top of stack is : %d\n", Top());
    return 0;
}