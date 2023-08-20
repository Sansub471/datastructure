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

    head = InsertAtPosition(head, 2, 67);
    printf("Inserting at position : ");
    Print(head);

    head = DeleteAtBeginning(head);
    printf("Delete at beginning : ");
    Print(head);

    head = DeleteAtPosition(head, 2);
    printf("Delete at position : ");
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

// Inserting functions
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

struct DNode* InsertAtPosition(struct DNode* head, int pos, int data){
    struct DNode* newnode = newDNode(data);
    if (head == NULL) return newnode;
    if (pos == 1) {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
        return head;
    }

    struct DNode* temp = head;
    for(int i=0; i < pos - 2; i++) temp = temp->next;
    newnode->next = temp->next;
    newnode->prev = temp;
    
    temp->next->prev = newnode;
    temp->next = newnode;
    return head;
}

// Deleting functions
struct DNode* DeleteAtBeginning(struct DNode* head){
    if (head == NULL ) return head;
    struct DNode* temp = head;

    // handle if there is only one node
    if(temp->next == NULL){
        free(temp);
        head = NULL;
        return head;
    }
    head = head->next;
    head->prev = NULL;
    free(temp);
    return head;
}

struct DNode* DeleteAtEnd(struct DNode* head){
    if (head == NULL) return head; // empty list

    struct DNode* temp = head;
    if(temp->next == NULL){
        free(temp);
        return NULL; // new head 
    }

    // get to last node
    while(temp->next != NULL) temp = temp->next;
    temp->prev->next = NULL;
    free(temp);
    return head;
}

struct DNode* DeleteAtPosition(struct DNode* head, int pos){
    if (head == NULL) return head; // empty list

    struct DNode* currentNode = head;

    // only one element
    if (currentNode->next == NULL){
        free(head); return NULL;
    }

    // at first position
    if (pos == 1){
        head = head->next;
        head->prev = NULL;
        free(currentNode);
        return head;
    }

    // goes upto (pos - 1)th node
    for(int i=0; i < pos - 2; i++) currentNode = currentNode->next;
    struct DNode* nextNode = currentNode->next; 
    currentNode->next = nextNode->next; // currentNode->next->next
    
    // if pos = last element
    if(nextNode->next != NULL) nextNode->next->prev = currentNode; // nextNode->prev
    free(nextNode); // currentNode->next
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

// double linked list completed.