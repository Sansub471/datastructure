#ifndef BST_QUEUE_TRAVERSAL_H
#define BST_QUEUE_TRAVERSAL_H

#ifndef LINKED_LIST_BST
#define LINKED_LIST_BST
struct LinkedListBst{
    struct BstNode* data;
    struct LinkedListBst* next;
};
#endif 

#ifndef BST_QUEUE
#define BST_QUEUE
struct Queue{
    struct LinkedListBst* front; // head
    struct LinkedListBst* rear; // tail

};
#endif

struct Queue* newQueue();
struct LinkedListBst* newNode(struct BstNode* x);

void Enqueue(struct Queue* Q, struct BstNode* x);
void Dequeue(struct Queue* Q);
struct BstNode* Front(struct Queue* Q);
bool IsEmpty(struct Queue* Q);

void PrintQueue(struct Queue* Q);
#endif