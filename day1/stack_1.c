#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 100
struct Stack{
    int A[MAX];
    int top;
};

// Stack operations
struct Stack* Push(struct Stack* stackpointer, int data);
int Pop(struct Stack* stackpointer); // Top function is also incorporated.
int Top(struct Stack* stackpointer);
bool IsEmpty(struct Stack* stackpointer);
void Print(struct Stack* stackpointer);

//helper function
struct Stack* newStack();
int main(){
    struct Stack* stackpointer = NULL;
    stackpointer = Push(stackpointer, 23); Print(stackpointer);
    stackpointer = Push(stackpointer, 2); Print(stackpointer);
    stackpointer = Push(stackpointer, 3); Print(stackpointer);
    stackpointer = Push(stackpointer, 13); Print(stackpointer);
    stackpointer = Push(stackpointer, 73); Print(stackpointer);
    stackpointer = Push(stackpointer, 77); Print(stackpointer);
    return 0;
}

struct Stack* newStack(){
    struct Stack* stack =(struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}

struct Stack* Push(struct Stack* stackpointer, int data){
    if (stackpointer == NULL){ 
       struct Stack* stack = newStack();
       stack->A[++stack->top] = data;
       return stack;
    }
    if (stackpointer->top == MAX -1){
        printf("Stack overflow.\n");
        return stackpointer;
    }
    stackpointer->A[++stackpointer->top] = data;
    return stackpointer;
}

void Print(struct Stack* stack){
    if (stack == NULL){printf("No stack.\n");return;}
    if (stack->top == -1){printf("Empty stack."); return;}
    printf("Stack : ");
    for(int i = 0; i<=stack->top; i++){
        printf("%d ", stack->A[i]);
    }
    printf("\n");
}