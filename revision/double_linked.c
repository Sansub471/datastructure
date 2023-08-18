#include<stdio.h>
#include<stdlib.h>

#include"double_linked.h"

int main(){
    struct DNode* head = newDNode(37);
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

//Print
void Print(struct DNode* head){
    struct DNode* temp = head;
    while(temp != NULL){
        printf("%d \t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}