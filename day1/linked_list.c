#include<stdio.h>
#include<stdlib.h>
#include"linked_list.h"
struct Node* headpoint;
int main()
{
    struct Node* head = NULL; // empty list
    // Inserting at the beginning
    printf("How many numbers?\n");
    int n, i, x;
    scanf("%d", &n);
    for (i=0; i<n; i++)
    {
        printf("Enter the number: \n");
        scanf("%d", &x);
        head = Insert(head, x);
        PrintList(head);
    }

    //Inserting at nth position
    printf("\nInserting at nth position: ");
    head = InsertPosition(head, 5, 1); // 5
    head = InsertPosition(head, 3, 2); // 5, 3
    head = InsertPosition(head, 6, 3); // 5, 3, 6 
    head = InsertPosition(head, 8, 2); // 5, 8, 3, 6
    head = InsertPosition(head, 9, 4); // 5, 8, 3, 9, 6
    PrintList(head);

    printf("Deleting from nth position : \n");
    head = DeletePositin(head, 2);
    PrintList(head);
    head = DeletePositin(head, 4);
    PrintList(head);
    head = DeletePositin(head, 1);
    PrintList(head);

    // Reverse list
    printf("The list is : ");
    PrintList(head);
    printf("The reversed list is : ");
    head = ReverseByIteration(head);
    PrintList(head);

    //Print by recursion
    printf("Recursion PrintList : ");
    PrintRecursion(head);

    //Insert at end
    printf("Insert at the end : ");
    head = InsertAtEnd(head, 777);
    PrintRecursion(head);
    head = InsertAtEnd(head, 32);
    PrintRecursion(head);
    head = InsertAtEnd(head, 45);
    PrintRecursion(head);

    // Reverse Print
    printf("Reverse print a list using recursion : ");
    ReversePrintRecursion(head);
    printf("\n");

    return 0;
}
struct Node* Insert(struct Node* head, int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    //(*temp).data = x;
    temp->data = x;
    temp->next = NULL;
    if (head != NULL) temp->next = head;
    head = temp;
    return head;
}

struct Node* InsertPosition(struct Node* head,int data, int n)
{
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
    temp1->data = data;
    temp1->next = NULL;
    if (n == 1) { 
        temp1 ->next = head;
        head = temp1;
        return head;
    }
    struct Node* temp2 = head;
    // need to reach upto n - 1 th node
    for(int i=0; i<n-2; i++)
    {
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
    return head;
}

struct Node* InsertAtEnd(struct Node* head, int data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    if (head == NULL){
        head = temp;  
        return head;
    }
    struct Node* temp1 = head;
    while(temp1->next != NULL) temp1 = temp1->next;
    temp1->next = temp;
    return head;
}

// Try deleting given value, first occurence or all occurences.
// Assume valid value if n is given.
struct Node* DeletePositin(struct Node* head, int n)
{
    struct Node* temp = head;
    if (n == 1)
    {
        head = temp->next; // (*temp).next
        free(temp);
        return head;
    }
    for (int i=0; i<n-2; i++)
    {
        temp = temp->next; //itereate the list upto n - 1 th Node
    }
    struct Node* temp1 = temp->next; // nth Node
    temp->next = temp1->next;// (n + 1) Node
    free(temp1);
    return head;
}

struct Node* ReverseByIteration(struct Node* head)
{
    struct Node* current = head;
    struct Node* prev = NULL;
    struct Node* next;
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

void PrintList(struct Node* head)
{
    while(head != NULL)
    {
        printf(" %d", head->data);
        head = head->next;
    }
    printf("\n");
}

void ReverseByRecursion(struct Node* p)
{
    // Base case : empty list or only one node
    if (p->next == NULL){
        headpoint = p;
        return;
    }
    ReverseByRecursion(p->next);
    struct Node* q = p->next;
    q->next = p;
    p->next = NULL;
}

void PrintRecursion(struct Node* head)
{
    if (head == NULL) {printf("\n"); return ;} // Exit condition
    printf("%d ", head->data);
    PrintRecursion(head->next);
}

void ReversePrintRecursion(struct Node* head)
{
    if (head == NULL) return;
    ReversePrintRecursion(head->next);
    printf("%d ", head->data);
}