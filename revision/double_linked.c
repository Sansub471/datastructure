#include<stdio.h>
#include<stdlib.h>

#include"double_linked.h"

int main(){
    struct DNode* head = newDNode(37);
    

    return 0;
}

struct DNode* newNode(int data){
    struct DNode* newnode = (struct DNode*)malloc(sizeof(struct DNode));
    newnode->prev = NULL;
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

