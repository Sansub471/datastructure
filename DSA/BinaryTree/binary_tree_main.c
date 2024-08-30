#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"binary_tree.c"
#define max(a,b) (((a) > (b)) ? (a) : (b))

int main(){
    struct BstNode* rootPtr = NULL; // setting tree as empty.
    rootPtr = Insert(rootPtr, 25);    rootPtr = Insert(rootPtr, 10);
    rootPtr = Insert(rootPtr, 30);    rootPtr = Insert(rootPtr, 9);
    rootPtr = Insert(rootPtr, 11);    rootPtr = Insert(rootPtr, 28);
    rootPtr = Insert(rootPtr, 32);    rootPtr = Insert(rootPtr, 8); 
    rootPtr = Insert(rootPtr, 12);    rootPtr = Insert(rootPtr, 9);     
    rootPtr = Insert(rootPtr, 11);    rootPtr = Insert(rootPtr, 27);    
    rootPtr = Insert(rootPtr, 29);    rootPtr = Insert(rootPtr, 31);    
    rootPtr = Insert(rootPtr, 34);

    int num = 8;
    bool result = Search(rootPtr, num);
    if (result){
        printf("The number %d is found.\n", num);
    }
    else{
        printf("The number %d is not found.\n", num);
    }
    int maxelement = FindMaxIterative(rootPtr);
    printf("The maximum element by iteration : %d \n", maxelement);
    maxelement = FindMaxRecursion(rootPtr);
    printf("The maximum element by recursion : %d \n", maxelement);

    printf("\n");
    int minelement = FindMinIterative(rootPtr);
    printf("The minimun element by iteration : %d \n", minelement);
    minelement = FindMinRecursion(rootPtr);
    printf("The minimum element by recursion : %d \n", minelement);

    int height = FindTreeHeight(rootPtr);
    printf("The height of the tree : %d \n", height);

    // Level Order Traversal
    printf("Level order traversal : \n");
    LevelOrder(rootPtr);

    //Depth first traversal
    printf("\n");
    printf("Preorder traversal : \n");
    Preorder(rootPtr); printf("\n");

    printf("Inorder traversal : \n"); 
    Inorder(rootPtr); printf("\n");

    printf("Postorder traversal : \n");
    Postorder(rootPtr); printf("\n");

    // Delete a node
    // Let's delete 30
    printf("\nLet's delete 30 from the tree : \n");
    printf("Before : ");
    Inorder(rootPtr); printf("\n");
    rootPtr = Delete(rootPtr, 30);
    printf("After : ");
    Inorder(rootPtr); printf("\n");

    // Check if binary tree
    // Method I
    bool isbst = IsBinarySearchTree(rootPtr);
    if (isbst){
        printf("\nThe tree given is a binary search tree.\n");
    }
    else{
        printf("\nThe given tree is not a binary search tree.\n");
    }
    //Method II
    isbst = IsBST(rootPtr);
    if (isbst){
        printf("\nThe tree given is a binary search tree.\n");
    }
    else{
        printf("\nThe given tree is not a binary search tree.\n");
    }

    //Inorder successor
    printf("\n Inorder successor of 25 is : ");
    struct BstNode* successor = Getsuccessor(rootPtr, 25);
    printf(" %d ", successor->data);

    printf("\n Inorder successor of 8 is : ");
    successor = Getsuccessor(rootPtr, 8);
    printf(" %d ", successor->data);

    printf("\n Inorder successor of 10 is : ");
    successor = Getsuccessor(rootPtr, 10);
    printf(" %d ", successor->data);
    return 0;
}
