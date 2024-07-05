//Reverse a string using Stack
//Linked list implementation of stack.
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"rev_string_stack.h"
//Insert at the end
struct SNode* Insert(struct SNode* head, char character){
    struct SNode* temp = (struct SNode*)malloc(sizeof(struct SNode));
    temp->data = character;
    temp->next = NULL;
    if (head == NULL){
        head = temp;
        return head;
    }
    struct SNode* temp1 = head;
    while(temp1->next != NULL) temp1 = temp1->next;
    temp1->next = temp;
    return head;
}

struct SNode* newNode(char data){
    struct SNode* newnode = (struct SNode*)malloc(sizeof(struct SNode));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

struct Stack* newStack(char data){
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->head = newNode(data);
    return stack;
}

bool IsEmpty(struct Stack* stack){
    if((stack->head == NULL) || (stack == NULL)){
        return true;
    }
    else{
        return false;
    }
}

char Top(struct Stack* stack){
    if (stack == NULL || IsEmpty(stack)){
        printf("Empty stack.\n");
        return -1;
    }
    return stack->head->data;
}

char Pop(struct Stack** stack)
{
    if(*stack == NULL || IsEmpty(*stack)){
        printf("Empty stack.\n");
        return -1;
    }
    char popped = Top(*stack);
    struct SNode* current = (*stack)->head;
    (*stack)->head = current->next;
    free(current);
    return popped;
}

struct Stack* Push(struct Stack* stackptr, char character){
    if ((stackptr == NULL) || (stackptr->head == NULL)){
        struct Stack* stack = newStack(character);
        if (stackptr != NULL) free(stackptr);
        return stack;
    }
    struct SNode* newnode = newNode(character);
    newnode->next = stackptr->head;
    stackptr->head = newnode;
    return stackptr;
}

struct SNode* ReverseListByStack(struct Stack* stack,  struct SNode* head){
    //push nodes to stack
    while(head != NULL){
        stack = Push(stack, head->data);
        head = head->next;
    }
    //pop nodes from stack and free the stack
    return stack->head;
}

void SPrint(struct SNode* head){
    while(head != NULL){
        printf("%c ", head->data);
        head = head->next;
    }
    printf("\n");
}