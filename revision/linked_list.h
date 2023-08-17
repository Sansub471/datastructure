#ifndef LINKED_LIST_H
#define LINKED_LIST_H



#ifndef NODE
#define NODE

struct Node {
    int data;
    struct Node* next;
};
#endif

struct Node* newNode(int data);
struct Node* InsertAtBeginning(struct Node* head, int data);
struct Node* InsertAtEnd(struct Node* head, int data);
struct Node* InsertAtPosition(struct Node* head, int pos, int data);
struct Node* DeletePosition(struct Node* head, int pos);

struct Node* ReverseByIteration(struct Node* head);
void ReverseByRecursion(struct Node* head);

struct Node* Reverse(struct Node* current, struct Node* prev);
struct Node* ReverseListRecursion(struct Node* head);

// printing
void Print(struct Node* head);
void PrintRecursion(struct Node* head);
void ReversePrintRecursion(struct Node* head);
#endif