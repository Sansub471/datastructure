#ifndef STACK_STRUCT_H
#define STACK_STRUCT_H
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
#endif