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
struct DNode* InsertAtPosition(struct DNode* head, int pos, int data);

struct DNode* DeleteAtBeginning(struct DNode* head);
struct DNode* DeleteAtEnd(struct DNode* head);
struct DNode* DeleteAtPosition(struct DNode* head, int pos);
//Print
void Print(struct DNode* head);

#endif