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

//create an empty stack
struct Stack* newStack();
int main(){
    struct Stack* stackpointer = NULL;
    stackpointer = Push(stackpointer, 23); Print(stackpointer);
    stackpointer = Push(stackpointer, 2);  Print(stackpointer);
    stackpointer = Push(stackpointer, 3);  Print(stackpointer);
    stackpointer = Push(stackpointer, 13); Print(stackpointer);
    stackpointer = Push(stackpointer, 73); Print(stackpointer);
    stackpointer = Push(stackpointer, 77); Print(stackpointer);
    int popped = Pop(stackpointer); 
    printf("Popped item : %d ", popped);
    Print(stackpointer);

    popped = Pop(stackpointer); 
    printf("Popped item : %d ", popped);
    Print(stackpointer);

    printf("Is stack empty ? %d ", IsEmpty(stackpointer));
    return 0;
}

struct Stack* newStack(){
    struct Stack* stack =(struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}

bool IsEmpty(struct Stack* stack){
    return stack->top == -1;
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

int Top(struct Stack* stack){
    if (stack == NULL || IsEmpty(stack)){
        printf("Empty stack.\n");
        return -1;
    }
    return stack->A[stack->top];
}

int Pop(struct Stack* stack){
    if (stack == NULL || IsEmpty(stack)){
        printf("Empty stack.\n");
        return -1;
    }
    if (stack->top != -1){
        int popped = Top(stack);
        stack->top--;
        return popped;
    }
    printf("Empty stack.\n");
    return -1;
}

void Print(struct Stack* stack){
    if (stack == NULL){printf("No stack.\n");return;}
    if (stack->top == -1){printf("Empty stack.\n"); return;}
    printf("Stack : ");
    for(int i = 0; i<=stack->top; i++){
        printf("%d ", stack->A[i]);
    }
    printf("\n");
}