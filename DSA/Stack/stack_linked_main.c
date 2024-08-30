#include<stdio.h>
#include"stack_linked.c"

int main(){
    struct Stack* stack = NULL;
    stack = Push(stack, 77); PrintStack(stack);
    stack = Push(stack, 56); PrintStack(stack);
    stack = Push(stack, 23); PrintStack(stack);
    stack = Push(stack, 12); PrintStack(stack);
    stack = Push(stack, 90); PrintStack(stack);
    printf("The top of stack is : %d \n", Top(stack));// -1 means empty.
    int popped;
    popped = Pop(&stack); // -1 means empty
    printf("Popped item : %d \n", popped);
    PrintStack(stack);

    popped = Pop(&stack); // -1 means empty
    printf("Popped item : %d \n", popped);
    PrintStack(stack);
    return 0;
}