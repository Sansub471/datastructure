#include<iostream>
#include<vector>
#include"binarySearchTree.hpp"

// BST Examples
SNode* BST_ONE(){
    SNode* root = newSNode(8);
    root->left = newSNode(3);
    root->right = newSNode(10);

    root->left->left = newSNode(1);
    root->left->right = newSNode(6);
    root->left->right->left = newSNode(4);
    return root;
}

CNode* BST_TWO(){
    CNode* root = newCNode(8);
    root->left = newCNode(3);
    root->right = newCNode(10);
    root->right->right = newCNode(14);

    root->left->left = newCNode(1);
    root->left->right = newCNode(6);
    root->left->right->left = newCNode(4);
    root->left->right->right = newCNode(7);
    return root;

}

template <typename T>
    bool SearchBST(T* root, int key){
        // check for emptiness
        if(root == nullptr) return false;

        // if current node is the key
        if(key == root->data) return true;
        if(key <  root->data) return SearchBST(root->left, key);
        if(key >  root->data) return SearchBST(root->right, key);

        // logically not necessary but the compiler expects a return type from every possible path
        return false;
    }


template <typename T>
    T* InsertBST(T* root, int data){
        if(root == nullptr) return new T(data); // create a new node

        if(data < root->data){
            root->left = InsertBST(root->left, data);
        }
        else if(data > root->data){
            root->right = InsertBST(root->right, data);
        }
        return root;
    }

template <typename T>
    T* findInorderSuccessor(T* root){
        T* current = root;
        // find the leftmost node(leaf)
        // This would be the minimum value in the right subtree
        // We could also use, max value in the left sub-tree.
        while(current && current->left != nullptr){
            current = current->left;
        }
        return current;
    }

template <typename T>
    T* deleteBSTNode(T* root, int data){
        if(root == nullptr) return root; // return if node is empty
        // find the node to be deleted.
        if(data < root->data){
            root->left = deleteBSTNode(root->left, data);
        }
        else if(data > root->data){
            root->right = deleteBSTNode(root->right, data);
        }
        //this implies data == root->data case
        else{
            // if the node is with only left child or no child
            if(root->left == nullptr){
                T* temp = root->right;
                delete root;
                return temp;
            } // only right child
            else if(root->right == nullptr){
                T* temp = root->left;
                delete root;
                return temp;
            }

            // if the node has two children
            T* temp = findInorderSuccessor(root->right);

            // place the inorder successor in position of the node to be deleted
            root->data = temp->data;

            // delete the inorder successor
            root->right = deleteBSTNode(root->right, temp->data);
        }
        return root;
    }

template<typename T>
    T* createBSTree(T* root, std::vector<int>& treeElems){
        for(const auto& elem : treeElems){
            root = InsertBST(root, elem);
        }
        return root;
    }