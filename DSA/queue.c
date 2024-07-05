// Queue implementation using array
// Operations in queue is O(1) or contant
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAX_SIZE 100

struct Queue{
    int A[MAX_SIZE];
    int front;
    int rear;
};
void Enqueue(struct Queue** Q, int data);
void Dequeue(struct Queue** Q);
int Front(struct Queue* Q);
bool IsEmpty(struct Queue* Q);

void Print(struct Queue* Q);

int main()
{   
    // create a queue
    struct Queue* Q = (struct Queue*)malloc(sizeof(struct Queue));
    Q->front = -1;
    Q->rear = -1;
    Enqueue(&Q, 2);
    Enqueue(&Q, 3);
    Enqueue(&Q, 4);
    Enqueue(&Q, 5);
    Enqueue(&Q, 17);
    Enqueue(&Q, 77);
    Print(Q);
    printf("Dequeue : \n");
    Dequeue(&Q);
    Print(Q);
    Dequeue(&Q);
    Print(Q);
    return 0;
}

bool IsEmpty(struct Queue* Q){
    if (Q->front == -1 && Q->rear == -1){
        return true;
    }
    else{
        return false;
    }
}

void Enqueue(struct Queue** Q, int data){
    if((*Q)->rear == MAX_SIZE - 1 ){return;}//full
    else if (IsEmpty(*Q)){
        (*Q)->front = 0;
        (*Q)->rear = 0;
    }
    else{(*Q)->rear = (*Q)->rear + 1;}
    (*Q)->A[(*Q)->rear] = data;
}

void Dequeue(struct Queue** Q){
    if(IsEmpty(*Q)){return;}
    else if ((*Q)->front == (*Q)->rear){ // one element
        (*Q)->front = -1;
        (*Q)->rear = -1;
    }
    else{
        (*Q)->front = (*Q)->front + 1;
    }
}

int Front(struct Queue* Q){
    if (IsEmpty(Q)){return -1;}
    return Q->A[Q->front];
}

void Print(struct Queue* Q){

    printf("Queue : ");
    struct Queue* tempQ = (struct Queue*)malloc(sizeof(struct Queue));
    tempQ->front = -1;
    tempQ->rear = -1;

    int i;
    for (i = Q->front; i <= Q->rear; i++) {
        Enqueue(&tempQ, Q->A[i]);
    }

    while (!IsEmpty(tempQ)) {
        printf("%d ", Front(tempQ));
        Dequeue(&tempQ);
    }
    // Free the memory allocated for the temporary queue
    free(tempQ);
    printf("\n");
    printf("The front : %d \n", Q->front);
    printf("The rear  : %d \n", Q->rear);
    printf("\n");
}