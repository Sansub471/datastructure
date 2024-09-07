#include<vector>

#include"AVLTree.hpp"


// To create a new node
Node* newNode(int data){
    Node* root = new Node(data);
    return root;
}

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

// Get the balance factor of each node
int getBalanceFactor(Node* node){
    if(node == nullptr) return 0;
    return height(node->left) - height(node->right);
}

// insert new node to AVL tree
Node* insertNode(Node* node, int key){
    // insert the node at appropriate position, BST insert
    if(node == nullptr) return newNode(key);
    if(key < node->data) node->left = insertNode(node->left, key);
    else if(key > node->data) node->right = insertNode(node->right, key);
    else return node; // leafNode and key == node->data 

    // update the balance factor for each node, nodes in the path of newly
    // inserted node and balance the tree 
    node->height = 1 + max(height(node->left), height(node->right)); // newNode inserted in this path, so +1
    int balanceFactor = getBalanceFactor(node);

    // rotation if BF is greater than 1 or less than -1 
    if(balanceFactor > 1){
        if(key < node->left->data){
            return rightRotate(node);
        }else if(key > node->left->data){
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    }

    if(balanceFactor < -1){
        if(key > node->right->data){
            return leftRotate(node);
        }else if(key < node->right->data){
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    }
    return node; // tree is balanced simply return the root
}


int main(){
    // Create an array to insert elements into AVL tree
    std::vector<int> avltree {33,13,53,61,13,21,11,12,8,9};
    Node* root = nullptr; // empty AVL tree
    for(const auto& elem: avltree){
        root = insertNode(root, elem);
        std::cout<<"AVL Tree: inorder DFS: "; inorderDFS(root); std::cout<<std::endl;
    }

    std::cout<<"\nFinal AVL Tree: inorder DFS: "; inorderDFS(root); std::cout<<std::endl;

    // // AVL tree with Left-Right rotation
    // std::vector<int> lravl {50,30,70,10,40,35};
    // Node* root1 = nullptr;
    // std::cout<<"\nAVL Tree with left-right rotation."<<std::endl;
    // for(const auto& elem : lravl){
    //     root1 = insertNode(root1, elem);
    //     std::cout<<"AVL Tree: inorder DFS: "; inorderDFS(root1); std::cout<<std::endl;
    // }
    // std::cout<<"\nAVL Tree: inorder DFS: "; inorderDFS(root1); std::cout<<std::endl;
    return 0;
}