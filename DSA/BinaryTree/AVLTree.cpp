#include"AVLTree.hpp"

// Calculate height
int height(Node* node){
    if (node == nullptr) return 0;
    return node->height;
}

int max(int a, int b){
    return (a > b) ? a : b;
}

// Rotate right
Node* rightRotate(Node* Y){
    Node* X = Y->left;
    Node* temp = X->right;
    X->right = Y;
    Y->left = temp;
    Y->height = max(height(Y->left), height(Y->right)) + 1;
    X->height = max(height(X->left), height(X->right)) + 1;
    return X;
}

// Rotate left
Node* leftRotate(Node* X){
    Node* Y = X->right;
    Node* temp = Y->left;
    Y->left = X;
    X->right = temp;
    X->height = max(height(X->left), height(X->right)) + 1;
    Y->height = max(height(Y->left), height(Y->right)) + 1;
    return Y;
}

int main(){
    return 0;
}