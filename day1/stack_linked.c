//Stack implementation using linked list
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node{
    int data;
    struct Node* next;
};

struct Stack{
    struct Node* head;
};

// Operations
struct Stack* Push(struct Stack* stackptr, int data);
int Pop(struct Stack* stack);
int Top(struct Stack* stack);
bool IsEmpty(struct Stack* stack);

void Print(struct Stack* stack);

//getnew stack
struct Stack* newStack(int data);

int main(){
    struct Stack* stack = NULL;
    stack = Push(stack, 77); Print(stack);
    stack = Push(stack, 56); Print(stack);
    stack = Push(stack, 23); Print(stack);
    stack = Push(stack, 12); Print(stack);
    stack = Push(stack, 90); Print(stack);
    printf("The top of stack is : %d ", Top(stack));
    return 0;
}

struct Node* newNode(int data){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

struct Stack* newStack(int data){
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->head = newNode(data);
    return stack;
}

bool IsEmpty(struct Stack* stack){
    if(stack->head == NULL){
        return true;
    }
    else{
        return false;
    }
}

struct Stack* Push(struct Stack* stackptr, int data){
    if (stackptr == NULL){ // handle empty stack
        struct Stack* stack = newStack(data);
        return stack;
    }
    struct Node* newnode = newNode(data);
    newnode->next = stackptr->head;
    stackptr->head = newnode;
    return stackptr;
}

int Top(struct Stack* stack){
    if (stack == NULL || IsEmpty(stack)){
        printf("Empty stack.\n");
        return -1;
    }
    return stack->head->data;
}

void Print(struct Stack* stack){
    if(stack == NULL || IsEmpty(stack)){
        printf("Empty stack.\n");
        return;
    }
    printf("Stack : ");
    // get the linked list header, and print like the list
    struct Node* current = stack->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}