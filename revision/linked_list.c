#include<stdio.h>
#include<stdlib.h>

#include"linked_list.h"

int main(){
    struct Node* head = newNode(23);
    head = InsertAtBeginning(head, 34);
    head = InsertAtEnd(head, 77);
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
    if (head != NULL) temp->next = head->next;
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

void Print(struct Node* head){
    while(head != NULL){
        printf("%d \t", head->data);
        head = head->next;
    }
    printf("\n");
    //free(temp);
}