//Reverse a string using Stack
//Linked list implementation of stack.
#include <stdio.h>
#include <stdlib.h>

#include"rev_string_stack.h"

int main() {
    char *string = (char *)malloc(MAX_LENGTH * sizeof(char));

    printf("Enter a string: ");
    fgets(string, MAX_LENGTH, stdin);

    printf("You entered: %s", string);

    //Create a link list of characters
    struct SNode* head = NULL;

    printf("Characters: ");
    char *ptr = string; // Initialize a pointer to the start of the string
    while (*ptr != '\0') {
        printf("%c ", *ptr);
        head = Insert(head, *ptr);
        ptr++; 
    }
    printf("\n");
    printf("The characters in linked list are : ");
    SPrint(head);
    
    //Create a stack using linked list
    struct Stack* stack = NULL;
    head = ReverseListByStack(stack, head);
    printf("The reversed string is: ");
    SPrint(head);
    free(stack);
    free(string);
    return 0;
}
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

struct Stack* Push(struct Stack* stackptr, char character){
    if (stackptr == NULL){
        struct Stack* stack = newStack(character);
        return stack;
    }
    struct SNode* newnode = newNode(character);
    newnode->next = stackptr->head;
    stackptr->head = newnode;
    return stackptr;
}

struct SNode* ReverseListByStack(struct Stack* stack,  struct SNode* head){
    while(head != NULL){
        stack = Push(stack, head->data);
        head = head->next;
    }
    return stack->head;
}


void SPrint(struct SNode* head){
    while(head != NULL){
        printf("%c ", head->data);
        head = head->next;
    }
    printf("\n");
}