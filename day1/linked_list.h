#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#ifndef NODE
#define NODE
struct Node
{
    int data;
    struct Node* next;
};
#endif
// Insert at the beginning
struct Node* Insert(struct Node* head, int x);

// Insert at nth position
struct Node* InsertPosition(struct Node* head, int data, int n);

//Insert at the end.
struct Node* InsertAtEnd(struct Node* head, int data);

//Delete at nth position
struct Node* DeletePosition(struct Node* head, int n);

//Reverse by iteration
struct Node* ReverseByIteration(struct Node* head);

//Reverse by recursion
void ReverseByRecursion(struct Node* current);

// Print functions
void PrintList(struct Node*);
void PrintRecursion(struct Node* head);
void ReversePrintRecursion(struct Node* head);
#endif