// Queue implementation using array
// Operations in queue is O(1) or contant
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAX_SIZE 10

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
    Enqueue(&Q, 55);
    Enqueue(&Q, 71);
    Enqueue(&Q, 89);
    Enqueue(&Q, 29);

    Enqueue(&Q, 19);
    Enqueue(&Q, 90);
    Print(Q);
    printf("Dequeue : \n");
    Dequeue(&Q);
    Print(Q);
    Dequeue(&Q);
    Print(Q);

    Enqueue(&Q, 19);
    Enqueue(&Q, 90);
    Print(Q);

    printf("Dequeue : \n");
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
    if((((*Q)->rear + 1) % MAX_SIZE) == (*Q)->front){return;}//full
    else if (IsEmpty(*Q)){
        (*Q)->front = 0;
        (*Q)->rear = 0;
    }
    else{(*Q)->rear = ((*Q)->rear + 1) % MAX_SIZE;}
    (*Q)->A[(*Q)->rear] = data;
}

void Dequeue(struct Queue** Q){
    if(IsEmpty(*Q)){return;}
    else if ((*Q)->front == (*Q)->rear){ // one element
        (*Q)->front = -1;
        (*Q)->rear = -1;
    }
    else{
        (*Q)->front = ((*Q)->front + 1) % MAX_SIZE;
    }
}

int Front(struct Queue* Q){
    if (IsEmpty(Q)){return -1;}
    return Q->A[Q->front];
}

void Print(struct Queue* Q){
    if (IsEmpty(Q)){printf("Empty.\n"); return ;}

    printf("Queue : ");
    struct Queue* tempQ = (struct Queue*)malloc(sizeof(struct Queue));
    tempQ->front = -1;
    tempQ->rear = -1;

    int current_pos = Q->front;
    int final = Q->rear;
    while(current_pos != final){
        Enqueue(&tempQ, Q->A[current_pos]);
        current_pos = (current_pos + 1) % MAX_SIZE;
    }
    Enqueue(&tempQ, Q->A[current_pos]);

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