#include"redBlackTree.hpp"

void RedBlackTree::initializeNULLNode(Node* node, Node* parent){
    node->data = 0;
    node->parent = parent;
    node->left = nullptr;
    node->right = nullptr;
    node->color = false;
}

void RedBlackTree::preOrderHelper(Node* node){

}


void RedBlackTree::inOrderHelper(Node* node){

}

void RedBlackTree::postOrderHelper(Node* node){

}
int main(){
    return 0;
}