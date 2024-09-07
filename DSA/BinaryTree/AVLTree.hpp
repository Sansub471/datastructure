#ifndef AVL_TREE
#define AVL_TREE


#ifndef AVL_TREE_NODE
#define AVL_TREE_NODE

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        int height;

        Node(int key){
            data = key; 
            left = nullptr;
            right = nullptr;
            height = 1;
        }
};
#endif

// For traversal functions
#include"binarySearchTree.hpp"

// To create a new node
Node* newNode(int data);

// calculate height
int height(Node* node);

int max(int a, int b);
Node* rightRotate(Node* Y);
Node* leftRotate(Node* X);

int getBalanceFactor(Node* node);

// Insert a node
Node* insertNode(Node* node, int key);



#endif
