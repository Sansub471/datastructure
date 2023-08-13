#include<stdio.h>
#include<stdlib.h>

#include"linked_list.h"

int main(){
    struct Node* head = newNode(23);
    printf("The data is %d", head->data);
    return 0;
}

struct Node* newNode(int data){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}