#include<stdio.h>
#include<stdlib.h>


struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};
// newnode
struct Node* GetNewNode(int x);

// Insert at the beginning
struct Node* InsertAtBeginning(struct Node* head, int x);

// Printing functions
void Print(struct Node* head);
int main()
{
    struct Node* head = NULL; // head pointer
    head = InsertAtBeginning(head, 23);//23
    head = InsertAtBeginning(head, 34);// 34 23
    head = InsertAtBeginning(head, 77);// 77 34 23
    head = InsertAtBeginning(head, 90);// 90 77 34 23
    printf("The list is : ");
    Print(head);
    return 0;
}
struct Node* GetNewNode(int x){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;

}

struct Node* InsertAtBeginning(struct Node* head, int x)
{
    struct Node* newNode = GetNewNode(x);
    if (head == NULL){head = newNode; return head;} // empty list
    head->prev = newNode;
    newNode->next = head; 
    head = newNode;
    return head;
}

void Print(struct Node* head)
{  
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}