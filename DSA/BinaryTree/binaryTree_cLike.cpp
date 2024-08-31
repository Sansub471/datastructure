// The structure implementation is more C like
#include<iostream>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

// create a new node
struct Node* newNode(int data){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data; // same as (*node).data = data
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

// preorder traversal
void Preorder(struct Node* node){
    if(node == nullptr){
        return;
    }
    std::cout<< node->data << ", ";
    Preorder(node->left);
    Preorder(node->right);
}

// inorder traversal
void Inorder(struct Node* node){
    if(node == nullptr){
        return;
    }
    Inorder(node->left);
    std::cout<< node->data<<", ";
    Inorder(node->right);
}

// post order traversal
void Postorder(struct Node* node){
    if (node == nullptr){
        return;
    }
    Postorder(node->left);
    Postorder(node->right);
    std::cout<< node->data<< ", ";
}

int main(){
    struct Node* root = newNode(7);
    root->left = newNode(9);
    root->right = newNode(13);

    root->left->left = newNode(5);
    root->left->right = newNode(3);

    root->right->left = newNode(2);
    root->right->right = newNode(11);

    std::cout<<"\nThe pre-order traversal : "; Preorder(root);
    std::cout<<"\nThe in-order traversal  : "; Inorder(root);
    std::cout<<"\nThe post-order traversal: "; Postorder(root);
    std::cout<<std::endl;
    return 0;

}
