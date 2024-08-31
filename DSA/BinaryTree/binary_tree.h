#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#ifndef BST_NODE
#define BST_NODE
struct BstNode{
    int data;
    struct BstNode* left;
    struct BstNode* right;
};
#endif

struct BstNode* newBstNode(int data);
struct BstNode* Insert(struct BstNode* rootPtr, int data);

// Find min and max element.
int FindMinIterative(struct BstNode* rootPtr);
int FindMaxIterative(struct BstNode* rootPtr);
int FindMinRecursion(struct BstNode* rootPtr);
int FindMaxRecursion(struct BstNode* rootPtr);

// Recursive approach
int FindTreeHeight(struct BstNode* rootPtr);
bool Search(struct BstNode* rootPtr, int data);

//Level order traversal
void LevelOrder(struct BstNode* rootPtr);

//Depth-first traversal techniques
void Preorder(struct BstNode* rootPtr);
void Inorder(struct BstNode* rootPtr);
void Postorder(struct BstNode* rootPtr);

// check if a given binary tree is BST
bool IsSubtreeLesser(struct BstNode* rootPtr, int value);
bool IsSubtreeGreater(struct BstNode* rootPtr, int value);
bool IsBinarySearchTree(struct BstNode* rootPtr);

bool IsBstUtil(struct BstNode* rootPtr, int minValue, int maxValue);
bool IsBST(struct BstNode* rootPtr);

// Delete a node
struct BstNode* Delete(struct BstNode* rootPtr, int data);

//Function to find successor
struct BstNode* Getsuccessor(struct BstNode* rootPtr, int data);
struct BstNode* Find(struct BstNode* rootPtr, int data);
#endif