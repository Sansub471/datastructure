#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"bst_queue_traversal.h"

struct Queue* newQueue(){
    struct Queue* temp = (struct Queue*)malloc(sizeof(struct Queue));
    temp->front = NULL;
    temp->rear = NULL;
    return temp;
}

struct LinkedListBst* newNode(struct BstNode* x){
    struct LinkedListBst* temp = (struct LinkedListBst*)malloc(sizeof(struct LinkedListBst));
    temp->data = x;
    temp->next = NULL;
    return temp;
}

bool IsEmpty(struct Queue* Q){
    if (Q == NULL) return true;
    if (Q->front == NULL && Q->rear == NULL){
        return true;
    }
    else{
        return false;
    }
}

void Enqueue(struct Queue* Q, struct BstNode* x){
    struct LinkedListBst* newnode = newNode(x);
    if (Q->front == NULL && Q->rear==NULL){
        Q->front = newnode;
        Q->rear = newnode;
        return;
    }
    Q->rear->next = newnode;
    Q->rear = newnode;
}

void Dequeue(struct Queue* Q){
    if (IsEmpty(Q)) return; // empty queue
    
    struct LinkedListBst* temp = Q->front;
    if (Q->front == Q->rear){ // only one element
        Q->front = NULL;
        Q->rear = NULL;
    }
    else{Q->front = Q->front->next;}
    free(temp);
}

struct BstNode* Front(struct Queue* Q){
    // Call this function only when Q is not empty
    return Q->front->data;
}

void PrintQueue(struct Queue* Q){
    if (IsEmpty(Q)){
        printf("Empty.\n");
        return;
    }
    struct LinkedListBst* head = Q->front;
    while(head != NULL){
        printf("%d ", head->data->data);
        head = head->next;
    }
    printf("\n");
}