//Stack implementation using linked list
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"stack_linked.h"

int main(){
    struct Stack* stack = NULL;
    stack = Push(stack, 77); PrintStack(stack);
    stack = Push(stack, 56); PrintStack(stack);
    stack = Push(stack, 23); PrintStack(stack);
    stack = Push(stack, 12); PrintStack(stack);
    stack = Push(stack, 90); PrintStack(stack);
    printf("The top of stack is : %d \n", Top(stack));// -1 means empty.
    int popped;
    popped = Pop(&stack); // -1 means empty
    printf("Popped item : %d \n", popped);
    PrintStack(stack);

    popped = Pop(&stack); // -1 means empty
    printf("Popped item : %d \n", popped);
    PrintStack(stack);
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

int Pop(struct Stack** stack)
{
    if(*stack == NULL || IsEmpty(*stack)){
        printf("Empty stack.\n");
        return -1;
    }
    int popped = Top(*stack);
    struct Node* current = (*stack)->head;
    (*stack)->head = current->next;
    free(current);
    return popped;
}


void PrintStack(struct Stack* stack){
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