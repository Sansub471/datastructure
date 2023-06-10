//This is my implementation
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node{
    int data;
    struct Node* next;
};

// You can assume any side as front or rear
// and implement accordingly
struct Queue{
    struct Node* front; // head
    struct Node* rear; // tail

};

struct Queue* newQueue();
struct Node* newNode(int x);

void Enqueue(struct Queue* Q, int x);
void Dequeue(struct Queue* Q);
int Front(struct Queue* Q);
bool IsEmpty(struct Queue* Q);

void PrintQueue(struct Queue* Q);

int main(){
    struct Queue* Q = newQueue();
    printf("Enqueue elements. \n");
    Enqueue(Q, 23);
    Enqueue(Q, 32);
    Enqueue(Q, 53);
    Enqueue(Q, 77);
    Enqueue(Q, 17);
    Enqueue(Q, 81);
    
    PrintQueue(Q);
    
    printf("Dequeue operation. \n");
    Dequeue(Q);
    Dequeue(Q);
    
    PrintQueue(Q);
    printf("Enqueue element.\n");
    Enqueue(Q, 777);
    PrintQueue(Q);

    printf("Dequeue element.\n");
    Dequeue(Q);
    PrintQueue(Q);
    return 0;
}
struct Queue* newQueue(){
    struct Queue* temp = (struct Queue*)malloc(sizeof(struct Queue));
    temp->front = NULL;
    temp->rear = NULL;
    return temp;
}

struct Node* newNode(int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
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

void Enqueue(struct Queue* Q, int x){
    struct Node* newnode = newNode(x);
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
    
    struct Node* temp = Q->front;
    if (Q->front == Q->rear){ // only one element
        Q->front = NULL;
        Q->rear = NULL;
    }
    else{Q->front = Q->front->next;}
    free(temp);
}

int Front(struct Queue* Q){
    if (Q == NULL) return -1; // no queue
    if (Q->front == NULL) return -1; // empty queue, rear is also NULL
    return Q->front->data;
}

void PrintQueue(struct Queue* Q){
    if (IsEmpty(Q)){
        printf("Empty.\n");
        return;
    }
    struct Node* head = Q->front;
    printf("Queue : ");
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}