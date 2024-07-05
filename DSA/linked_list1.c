// Try to grasp this concept very well.
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};
 
// Address of the head node
void Insert(struct Node**, int x);
void Print(struct Node*);

int main()
{
    struct Node* head = NULL; // empty list
    printf("How many numbers?\n");
    int n, i, x;
    scanf("%d", &n);
    for (i=0; i<n; i++)
    {
        printf("Enter the number: \n");
        scanf("%d", &x);
        Insert(&head, x);
        Print(head);
    }
    
    return 0;
}
// head is a pointer of type Node
// passing its address in main, &head, means address of the pointer is being passed
// hence in function definition Node**
void Insert(struct Node** head, int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    //(*temp).data = x;
    temp->data = x;
    temp->next = NULL;
    if (*head != NULL) temp->next = *head;
    *head = temp;
}
void Print(struct Node* head){
    printf("List is : ");
    while(head != NULL)
    {
        printf(" %d", head->data);
        head = head->next;
    }
    printf("\n");
}