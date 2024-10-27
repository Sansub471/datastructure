#include<stdio.h>
#include<stdlib.h>

#include"linked_list.c"

int main()
{
    struct Node* head = NULL; // empty list
    // Inserting at the beginning
    printf("How many numbers?\n");
    int n, i, x;
    scanf_s("%d", &n);
    for (i=0; i<n; i++)
    {
        printf("Enter the number: \n");
        scanf_s("%d", &x);
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
    head = DeletePosition(head, 2);
    PrintList(head);
    head = DeletePosition(head, 4);
    PrintList(head);
    head = DeletePosition(head, 1);
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