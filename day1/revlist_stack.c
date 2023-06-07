//Reverse a linked list by stack
//Stack is implemented using linked list
#include<stdio.h>
#include"revlist_stack.h"

int main()
{
    //Create a linked list
    struct Node* head = NULL;
    head = InsertAtEnd(head, 23);
    head = InsertAtEnd(head, 45);
    head = InsertAtEnd(head, 78);
    head = InsertPosition(head, 17, 2);
    head = Insert(head, 13);
    head = Insert(head , 77);
    printf("The list is : ");
    PrintList(head);

    //Create a stack 
    struct Stack* stack = NULL;
    head = ReverseListByStack(stack, head);
    printf("Reverse list is: ");
    PrintList(head);
    return 0;
}
struct Node* ReverseListByStack(struct Stack* stack, struct Node* head){
    //push all elements of the list to stack
    while(head != NULL){
        stack = Push(stack, head->data); //push data to stack
        head = head->next;
    }
    return stack->head;
}