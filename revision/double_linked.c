#include<stdio.h>
#include<stdlib.h>

#include"double_linked.h"

int main(){
    struct DNode* head = NULL; // new double linked list
    head = InsertBeginning(head, 23);
    head = InsertBeginning(head, 45);
    head = InsertBeginning(head, 56);
    head = InsertBeginning(head, 78);
    printf("Inserting at the beginning : ");
    Print(head);

    head = InsertAtEnd(head, 89);
    head = InsertAtEnd(head, 12);
    printf("Inserting at the end : ");
    Print(head);


    return 0;
}

struct DNode* newDNode(int data){
    struct DNode* newnode = (struct DNode*)malloc(sizeof(struct DNode));
    newnode->prev = NULL;
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

struct DNode* InsertBeginning(struct DNode* head, int data){
    struct DNode* newnode = newDNode(data);
    if (head == NULL) return newnode;
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
    return head;
}

struct DNode* InsertAtEnd(struct DNode* head, int data){
    struct DNode* newnode = newDNode(data);
    if(head == NULL) return newnode;

    struct DNode* temp = head;
    // going to last node
    while(temp->next != NULL) temp = temp->next; 
    //build the links
    temp->next = newnode;
    newnode->prev = temp;
    return head;
}

//Print
void Print(struct DNode* head){
    struct DNode* temp = head;
    while(temp != NULL){
        printf("%d \t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}