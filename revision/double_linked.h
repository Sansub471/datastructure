#ifndef DOUBLE_LINKED_LIST
#define DOUBLE_LINKED_LIST

#ifndef DOUBLE_NODE
#define DOUBLE_NODE

struct DNode{
    int data;
    struct DNode* prev;
    struct DNode* next;
};
#endif

struct DNode* newDNode(int data);
struct DNode* InsertBeginning(struct DNode* head, int data);
struct DNode* InsertAtEnd(struct DNode* head, int data);

//Print
void Print(struct DNode* head);

#endif