#include<stdio.h>
#include<stdlib.h>


struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};
// newnode
struct Node* GetNewNode(int x);
struct Node* InsertAtBeginning(struct Node* head, int x);
struct Node* InsertAtEnd(struct Node* head, int x);
struct Node* InsertAtPosition(struct Node* head, int x, int n);

struct Node* DeleteAtBeginning(struct Node* head);
struct Node* DeleteAtEnd(struct Node* head);

// Printing functions
void Print(struct Node* head);
//Reverse Print
void ReversePrint(struct Node* head);
int main()
{
    struct Node* head = NULL; // head pointer
    head = InsertAtBeginning(head, 23);//23
    head = InsertAtBeginning(head, 34);// 34 23
    head = InsertAtBeginning(head, 77);// 77 34 23
    head = InsertAtBeginning(head, 90);// 90 77 34 23
    printf("The list is : ");
    Print(head);

    printf("Inserting at the end : ");
    head = InsertAtEnd(head, 78);
    head = InsertAtEnd(head, 18);
    Print(head);

    printf("Reverse print : ");
    ReversePrint(head);

    printf("Inserting at positions: ");
    head = InsertAtPosition(head, 20, 1);
    Print(head);
    head = InsertAtPosition(head, 32, 5);
    Print(head);
    head = InsertAtPosition(head, 89, 2);
    Print(head);

    printf("Delete at the beginning : ");
    head = DeleteAtBeginning(head);
    Print(head);
    head = DeleteAtBeginning(head);
    Print(head);

    printf("Deleting at the end : ");
    head = DeleteAtEnd(head);
    Print(head);
    head = DeleteAtEnd(head);
    Print(head);
    head = DeleteAtEnd(head);
    Print(head);
    head = DeleteAtEnd(head);
    Print(head);
    head = DeleteAtEnd(head);
    Print(head);
    head = DeleteAtEnd(head);
    Print(head);
    head = DeleteAtEnd(head);
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

struct Node* InsertAtEnd(struct Node* head, int x)
{
    struct Node* newNode = GetNewNode(x);
    struct Node* temp = head;
    if (temp == NULL){head = newNode; return head;}
    while(temp->next != NULL){
        temp = temp->next;
    } // Going to last node
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

struct Node* InsertAtPosition(struct Node* head, int x, int n)
{
    struct Node* newNode = GetNewNode(x);
    if (head == NULL){head=newNode; return head;} // handle empty list
    // insert at the beginning
    if (n == 1){
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return head;
    }
    //Traverse upto n-1th node
    struct Node* temp = head;
    for(int i=0; i < n - 2; i++){temp = temp->next;}
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
    return head;
}

struct Node* DeleteAtBeginning(struct Node* head){
    if (head == NULL){return head;} // handle empty list
    //if there is only one element
    struct Node* temp  = head;
    if (temp->next == NULL){
        free(temp);
        head=NULL; 
        return head;
    }
    head = head->next;
    head->prev = NULL;
    free(temp);
    return head;
}

struct Node* DeleteAtEnd(struct Node* head){
    if (head == NULL){return NULL;} // handle empty list
    //handle one item
    if (head->next == NULL){
        free(head);
        return NULL;
    }
    struct Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
    return head;
}

void Print(struct Node* head)
{  
    if (head == NULL){printf("Empty list.\n");return;}
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void ReversePrint(struct Node* head)
{
    if (head == NULL){return;} //empty list
    while(head->next != NULL){head = head->next;} //get the last node
    //use prev link to print in reverse
    while(head != NULL){printf("%d ", head->data); head=head->prev;}
    printf("\n");
}