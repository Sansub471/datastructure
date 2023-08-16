#include<stdio.h>
#include<stdlib.h>

#include"linked_list.h"

int main(){
    struct Node* head = newNode(23);
    head = InsertAtBeginning(head, 34);
    head = InsertAtEnd(head, 77);
    head = InsertAtPosition(head, 2, 128);
    head = InsertAtPosition(head, 1, 337);
    Print(head);

    head = DeletePosition(head, 2);
    Print(head);
    return 0;
}

struct Node* newNode(int data){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

struct Node* InsertAtBeginning(struct Node* head, int data){
    struct Node* temp = newNode(data);
    if (head != NULL) temp->next = head;
    head = temp;
    return head;
}

struct Node* InsertAtEnd(struct Node* head, int data){
    struct Node* temp = newNode(data);
    if(head == NULL) return temp;

    struct Node* temp1 = head;
    while(temp1->next != NULL){
        temp1 = temp1->next;
    }
    temp1->next = temp;
    return head;
}

struct Node* InsertAtPosition(struct Node* head, int pos, int data){
    struct Node* temp = newNode(data);
    //if (head == NULL) return temp;
    if(pos == 1){
        temp->next = head;
        head = temp;
        return head;
    }
    struct Node* temp1 = head;
    for(int i=0; i < pos - 2; i++){
        temp1 = temp1->next;
    }
    temp->next = temp1->next;
    temp1->next = temp;
    return head;
}

struct Node* DeletePosition(struct Node* head, int pos){
    if (head == NULL) return head;
    struct Node* temp = head;

    if(pos == 1){
        head = temp->next;
        free(temp);
        return head;
    }

    for(int i=0; i < pos - 2; i++){
        temp = temp->next;
    }
    struct Node* temp1 = temp->next;
    temp->next = temp1->next;
    free(temp1);
    return head;
}

void Print(struct Node* head){
    while(head != NULL){
        printf("%d \t", head->data);
        head = head->next;
    }
    printf("\n");
    //free(temp);
}