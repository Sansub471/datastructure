#ifndef REV_STRING_STACK_H
#define REV_STRIBG_STACK_H

#define MAX_LENGTH 100

#ifndef STRING_NODE
#define STRING_NODE
struct SNode{
    char data;
    struct SNode* next;
};
#endif

#ifndef STRING_STACK
#define STRING_STACK
struct Stack{
    struct SNode* head;
};
#endif

//At the end.
struct SNode* Insert(struct SNode* head, char character);

struct SNode* newNode(char data);

struct Stack* newStack(char data);

struct Stack* Push(struct Stack* stackptr, char character);

struct SNode* ReverseListByStack(struct Stack* stack,  struct SNode* head);

void SPrint(struct SNode* head);
#endif