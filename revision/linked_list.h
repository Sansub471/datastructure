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
struct Node* InsertAtBeginning(int data);

#endif