#ifndef STACK_LINKED_H
#define STACK_LINKED_H
#include<stdbool.h>

#ifndef NODE
#define NODE
struct Node{
    int data;
    struct Node* next;
};
#endif

#ifndef STACK
#define STACK
struct Stack{
    struct Node* head;
};
#endif

// Operations
struct Stack* Push(struct Stack* stackptr, int data);
int Pop(struct Stack** stack);
int Top(struct Stack* stack);
bool IsEmpty(struct Stack* stack);

void PrintStack(struct Stack* stack);

//getnew stack
struct Node* newNode(int data);
struct Stack* newStack(int data);
#endif