#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#include"binary_tree.h"
#include"bst_queue_traversal.c"
#define max(a,b) (((a) > (b)) ? (a) : (b))

struct BstNode* newBstNode(int data){
    struct BstNode* newnode = (struct BstNode*)malloc(sizeof(struct BstNode));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct BstNode* Insert(struct BstNode* rootPtr, int data){
    if (rootPtr == NULL){ // empty tree
        rootPtr = newBstNode(data);
    }
    else if(data <= rootPtr->data){
        rootPtr->left = Insert(rootPtr->left, data); 
    }
    else{
        rootPtr->right = Insert(rootPtr->right, data);
    }
    return rootPtr;
} 

bool Search(struct BstNode* rootPtr, int data){
    if(rootPtr == NULL){
        return false;
    }
    else if(rootPtr->data == data){
        return true;
    }
    else if(data <= rootPtr->data){
        return Search(rootPtr->left, data); // return optional
    }
    else{
        return Search(rootPtr->right, data); // return optional
    }
}

int FindMinIterative(struct BstNode* rootPtr){
    if (rootPtr == NULL){
        printf("Empty tree.\n");
        return -1;
    }
    while(rootPtr->left != NULL){
        rootPtr = rootPtr->left;
    }
    return rootPtr->data;
}

int FindMaxIterative(struct BstNode* rootPtr){
    if(rootPtr == NULL){
        printf("Empty tree.\n");
    }
    while(rootPtr->right != NULL){
        rootPtr = rootPtr->right;
    }
    return rootPtr->data;
}

int FindMinRecursion(struct BstNode* rootPtr){
    if(rootPtr == NULL){
        // Empty tree
        return -1;
    }
    else if(rootPtr->left == NULL){
        return rootPtr->data;
    }
    // Search in left subtree
    return FindMinRecursion(rootPtr->left);
}

int FindMaxRecursion(struct BstNode* rootPtr){
    if(rootPtr == NULL){
        // Empty tree
        return -1;
    }
    else if(rootPtr->right == NULL){
        return rootPtr->data;
    }
    // Search in right subtree
    return FindMaxRecursion(rootPtr->right);
} 

int FindTreeHeight(struct BstNode* rootPtr){
    if(rootPtr == NULL){
        return -1; // empty tree has height -1
    }
    int leftHeight = FindTreeHeight(rootPtr->left);
    int rightHeight = FindTreeHeight(rootPtr->right);
    return max(leftHeight, rightHeight) + 1;
}

void LevelOrder(struct BstNode* rootPtr){
    if (rootPtr == NULL) return;
    struct Queue* Q = newQueue();
    //printing only
    printf("Traversed: \t\t Queue:\n");
    printf("\t\t\t");
    PrintQueue(Q);

    Enqueue(Q, rootPtr);
    //while there is at least one discovered node
    while (!IsEmpty(Q))
    {
        struct BstNode* current = Front(Q);
        printf("%d\t\t\t", current->data);
        if(current->left != NULL){
            Enqueue(Q, current->left);
        }
        if(current->right != NULL){
            Enqueue(Q, current->right);
        }
        Dequeue(Q); // Remove from front
        PrintQueue(Q);
    }
    free(Q); // Release the queue
}
 
void Preorder(struct BstNode* rootPtr){
    if (rootPtr==NULL) return; //base case
    printf("%d ", rootPtr->data);
    Preorder(rootPtr->left);
    Preorder(rootPtr->right);
}

void Inorder(struct BstNode* rootPtr){
    if (rootPtr == NULL) return ;
    Inorder(rootPtr->left);
    printf("%d ", rootPtr->data);
    Inorder(rootPtr->right);
}

void Postorder(struct BstNode* rootPtr){
    if (rootPtr == NULL) return;
    Postorder(rootPtr->left);
    Postorder(rootPtr->right);
    printf("%d ", rootPtr->data);
}

// check if a given binary tree is BST or not
// slow and cumbersome
// Method I
bool IsSubtreeLesser(struct BstNode* rootPtr, int value){
    if (rootPtr == NULL) return true;
    if (rootPtr->data <= value
    && IsSubtreeLesser(rootPtr->left, value)
    && IsSubtreeLesser(rootPtr->right, value))
    return true;
    else
        return false;
}

bool IsSubtreeGreater(struct BstNode* rootPtr, int value){
    if (rootPtr == NULL) return true;
    if (rootPtr->data > value
    && IsSubtreeGreater(rootPtr->left, value)
    && IsSubtreeGreater(rootPtr->right, value))
    return true;
    else
        return false;
}

bool IsBinarySearchTree(struct BstNode* rootPtr){
    if (rootPtr == NULL) return true;
    if (IsSubtreeLesser(rootPtr->left, rootPtr->data)
    && IsSubtreeGreater(rootPtr->right, rootPtr->data)
    && IsBinarySearchTree(rootPtr->left)
    && IsBinarySearchTree(rootPtr->right))
    return true;
    else 
        return false;
}

// Is Bst Method III
bool IsBstUtil(struct BstNode* rootPtr, int minValue, int maxValue){
    if (rootPtr == NULL) return true;
    if (rootPtr->data > minValue 
    && rootPtr->data < maxValue
    && IsBstUtil(rootPtr->left, minValue, rootPtr->data)
    && IsBstUtil(rootPtr->right, rootPtr->data, maxValue)){
    return true;
    }
    else{
        return false;
    }
}

bool IsBST(struct BstNode* rootPtr){
    return IsBstUtil(rootPtr, INT_MIN, INT_MAX);
}
// Delete a node

struct BstNode* FindMin(struct BstNode* rootPtr){
    if(rootPtr == NULL){
        // Empty tree
        return rootPtr;
    }
    else if(rootPtr->left == NULL){
        return rootPtr;
    }
    // Search in left subtree
    return FindMin(rootPtr->left);
}

struct BstNode* Delete(struct BstNode* rootPtr, int data){
    if (rootPtr == NULL){
        return rootPtr;
    }
    else if(data < rootPtr->data) { 
        rootPtr->left = Delete(rootPtr->left, data);
    }
    else if( data > rootPtr->data){ 
        rootPtr->right = Delete(rootPtr->right, data);
    }
    else{
        // Case 1: No child
        if(rootPtr->left == NULL && rootPtr->right == NULL){
            free(rootPtr);
            rootPtr = NULL;
        }
        //Case 2: One child
        else if (rootPtr->left == NULL){
            struct BstNode* temp = rootPtr;
            rootPtr = rootPtr->right;
            free(temp);
        }
        else if(rootPtr->right == NULL){
            struct BstNode* temp = rootPtr;
            rootPtr = rootPtr->left;
            free(temp);
        }
        // Case 3 : 2 Children
        else {
            // let's go with minimun value in right subtree
            struct BstNode* temp = FindMin(rootPtr->right);
            rootPtr->data = temp->data;
            rootPtr->right = Delete(rootPtr->right, temp->data);

        }
    }
    return rootPtr;   
}

struct BstNode* Find(struct BstNode* rootPtr, int data){
    if(rootPtr == NULL){
        return NULL;
    }
    else if(rootPtr->data == data){
        return rootPtr;
    }
    else if(data <= rootPtr->data){
        return Find(rootPtr->left, data); // return optional
    }
    else{
        return Find(rootPtr->right, data); // return optional
    }
}

// Function to find Inorder successor in a BST
struct BstNode* Getsuccessor(struct BstNode* rootPtr, int data){
    // Search the Node - O(h)
    struct BstNode* current = Find(rootPtr, data);
    if(current == NULL) return NULL;
    //case 1: Node has right subtree
    if (current->right != NULL){
        return FindMin(current->right);
    }
    else{
        struct BstNode* successor = NULL;
        struct BstNode* ancestor = rootPtr;
        while(ancestor != current){
            if(current->data < ancestor->data){
                successor = ancestor;
                // so far this is the deepest node for which current node is left
                ancestor = ancestor->left;
            }
            else{
                ancestor = ancestor->right;
            }
        }
        return successor;
    }
}