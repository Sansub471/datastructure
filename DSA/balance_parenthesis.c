#include<stdio.h>
#include<stdbool.h>
#include"rev_string_stack.c"

bool CheckBalancedParenthesis(char* ptr);
bool ArePair(char first, char second);

int main()
{
    //store the expression, give only parenthesis
    char *string = (char *)malloc(MAX_LENGTH * sizeof(char));
    printf("Give an expression of parenthesis : ");
    fgets(string, MAX_LENGTH, stdin);

    printf("Your expression is : %s", string);
    char* ptr = string;
    bool result = CheckBalancedParenthesis(ptr);
    if (result) {
        printf("The expression is balanced.");
    }
    else{
        printf("The expression is not balanced.");
    }
    return 0;
}

bool ArePair(char first, char second){
    if ((first == '(') && (second == ')')){
        return true;
    }
    else if ((first == '{') && (second == '}')){
        return true;
    }
    else if((first == '[') && (second == ']')){
        return true;
    }
    else{
        return false;
    }
    return false;
}

bool CheckBalancedParenthesis(char* ptr){
//Create a stack
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->head = NULL;
    while (*ptr != '\0') {
        if (((*ptr) == '(') || ((*ptr) == '{') || ((*ptr) == '[')){
            stack = Push(stack, *ptr);
        }
        else if(((*ptr) == ')') || ((*ptr) == '}') || ((*ptr) == ']')){
            if(IsEmpty(stack) || (!ArePair(Top(stack), *ptr))){
                free(stack);
                return false;
            }
            else{
                Pop(&stack);
            }
        } 
        ptr++; 
    }
    bool result = IsEmpty(stack)? true : false;
    free(stack);
    return result;
}