#include<iostream>
#include<vector>

#include"../localLib/treeTraversalPrint.hpp"
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
    Y->height = 1 + max(height(Y->left), height(Y->right));
    X->height = 1 + max(height(X->left), height(X->right));
    return X;
}

// Rotate left
Node* leftRotate(Node* X){
    Node* Y = X->right;
    Node* temp = Y->left;
    Y->left = X;
    X->right = temp;
    X->height = 1 + max(height(X->left), height(X->right));
    Y->height = 1 + max(height(Y->left), height(Y->right));
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
    node->height = 1 + max(height(node->left), height(node->right));
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

// Find minimum value in the subtree
Node* inorderSuccessor(Node* root){
    Node* current = root;
    while(current->left != nullptr) {
        current = current->left;
    }
    return current;
}

// delete a node
Node* deleteNode(Node* root, int key){
    // BST deleteNode steps
    if(root == nullptr) return root;
    if(key < root->data) root->left = deleteNode(root->left, key);
    else if(key > root->data) root->right = deleteNode(root->right, key);
    // key == root->data case
    else{
        // nodeToBeDeleted has one child or no child
        if((root->left == nullptr) || (root->right == nullptr)){
            Node* temp = root->left ? root->left : root->right;
            if(temp == nullptr){ // implies no child; leafnode 
                temp = root;
                root = nullptr;
            }else{ 
                // one child case; replace the node with its child node
                *root = *temp;
            }
            delete temp;
        }else{
            // nodeToBeDeleted has both children
            // minimun value in the right subtree, approach
            Node* temp = inorderSuccessor(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    // leafnode deletion case
    // no need to update height and BF for deleted leafnode, return to its parent
    if(root == nullptr) return root;

    // update the BF and balance the tree if required for each node
    root->height = 1 + max(height(root->left), height(root->right));
    int balanceFactor = getBalanceFactor(root);

    // balancing part
    if(balanceFactor > 1){
        if(getBalanceFactor(root->left) >= 0){
            return rightRotate(root);
        }else{
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    }

    if(balanceFactor < -1){
        if(getBalanceFactor(root->right) <= 0){
            return leftRotate(root);
        }else{
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }
    return root;
}

//printTree
void printTree(Node* root, std::string indent, bool last){
    if(root != nullptr){
        std::cout<<indent;
        if(last){
            std::cout<<"R----"; // Right child indicator
            indent += "     ";
        }else{
            std::cout<<"L----"; // Left child indicator
            indent += "|    ";
        }
        std::cout<< root->data <<"(BF="<<getBalanceFactor(root)<<")"<<std::endl;
        printTree(root->left, indent, false);
        printTree(root->right, indent, true);
    }
}


// helper function to create AVL tree from a given elements
Node* createAVLTree(std::vector<int>& avlElems, const std::string& task){
    Node* root = nullptr;
    std::cout<<"\nAVL Tree: " << task << std::endl;
    for(const auto& elem : avlElems){
        root = insertNode(root, elem);
        //std::cout<<"AVL Tree, inorder : "; inorderDFS(root); std::cout<<std::endl;
    }
    std::cout<<"\nFinal AVL Tree, inorder : "; Traversal::inorderDFS(root); std::cout<<std::endl;
    //printTree(root);
    printTree(root);
    return root;
}

// helper function to delete nodes: all cases checked.
Node* removeAVLNode(Node* root, int key, const std::string& task){
    std::cout<<"\nDeleting " << task << std::endl;
    std::cout<<"AVL Tree, inorder : "; Traversal::inorderDFS(root); std::cout<<std::endl;
    printTree(root);
    std::cout<<"Deleting node " << key << std::endl;
    root = deleteNode(root, key);
    std::cout<<"AVL Tree, inorder : "; Traversal::inorderDFS(root); std::cout<<std::endl;
    //printTree(root);
    return root;
}

// define helper functions inside this namespace to access the above functions, import as library
namespace AVL{
    void printAVLTree(Node* root){
        printTree(root, "", true);
    }

    // tree creation
    Node* AVLTree(std::vector<int>& avlElems, const std::string& task){
        return createAVLTree(avlElems, task);
    }

    Node* AVLremove(Node* root, int key, const std::string& task){
        return removeAVLNode(root, key, task);
    }
}