#include<stdio.h>
#include"rev_string_stack.c"

int main() {
    char *string = (char *)malloc(MAX_LENGTH * sizeof(char));

    printf("Enter a string: ");
    fgets(string, MAX_LENGTH, stdin);

    printf("You entered: %s", string);

    //Create a link list of characters
    struct SNode* head = NULL;

    printf("Characters: ");
    char *ptr = string; // Initialize a pointer to the start of the string
    while (*ptr != '\0') {
        printf("%c ", *ptr);
        head = Insert(head, *ptr);
        ptr++; 
    }
    printf("\n");
    printf("The characters in linked list are : ");
    SPrint(head);
    
    //Create a stack using linked list
    //This memory is being wasted
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->head = NULL;
    head = ReverseListByStack(stack, head);
    printf("The reversed string is: ");
    SPrint(head);
    free(stack);
    free(string);
    return 0;
}