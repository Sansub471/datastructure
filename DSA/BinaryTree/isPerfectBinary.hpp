#include"binaryTree.hpp"


// Example perfect binary tree
struct Node* perfectBinaryTree(){
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);

    root->left->left = newNode(4);
    root->left->right = newNode(5);

    root->right->left = newNode(6);
    root->right->right = newNode(7);

    // Add one more leaft node to make it not PBT
    //root->left->left->left = newNode(78);
    return root;
}

// Calculate the depth of a binary tree
int depth(struct Node* root){
    if(root==nullptr) return 0;
    int leftDepth = depth(root->left);
    int rightDepth = depth(root->right);
    return std::max(leftDepth, rightDepth) + 1;
}

bool isPerfectBinaryTree(struct Node* root, int d, int level=0){
    // empty root node
    if(root == nullptr) return true;

    // A leaf node, depth must equal to level + 1
    if(root -> left == nullptr && root -> right == nullptr){
        return (d == level + 1 );
    }

    // if the node has only one children, it is not a perfect binary tree
    if( root->left == nullptr || root->right == nullptr) return false;

    // if both left and right subtrees are PBT then the whole tree is PBT
    return isPerfectBinaryTree(root->left, d, level+1) && isPerfectBinaryTree(root->right, d, level+1);
}