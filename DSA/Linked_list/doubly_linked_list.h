#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#ifndef DOUBLE_NODE
#define DOUBLE_NODE
struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};
#endif

// newnode
struct Node* GetNewNode(int x);
struct Node* InsertAtBeginning(struct Node* head, int x);
struct Node* InsertAtEnd(struct Node* head, int x);
struct Node* InsertAtPosition(struct Node* head, int x, int n);

struct Node* DeleteAtBeginning(struct Node* head);
struct Node* DeleteAtEnd(struct Node* head);
struct Node* DeleteAtPosition(struct Node* head, int n);

// Printing functions
void Print(struct Node* head);
//Reverse Print
void ReversePrint(struct Node* head);
#endif