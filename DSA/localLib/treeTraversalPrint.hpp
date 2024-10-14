#include<iostream>

// Traversal functions
template <typename T>
    void preorderDFS(T* root){
        if(root == nullptr) return;
        std::cout<<root->data<<", ";
        preorderDFS(root->left);
        preorderDFS(root->right);
    }

template <typename T>
    void inorderDFS(T* root){
        if(root == nullptr) return;
        inorderDFS(root->left);
        std::cout<< root->data <<", ";
        inorderDFS(root->right);
    }

template <typename T>
    void postorderDFS(T* root){
        postorderDFS(root->left);
        postorderDFS(root->right);
        std::cout<< root->data <<", ";

    }

// tree print function
template <typename T>
    void printTree(T* root, std::string indent="", bool last=true){
        if(root != nullptr){
            std::cout<<indent;
            if(last){
                std::cout<<"R----"; // Right child indicator
                indent += "     ";
            }else{
                std::cout<<"L----"; // Left child indicator
                indent += "|    ";
            }
            std::cout<< root->data << std::endl;
            printTree(root->left, indent, false);
            printTree(root->right, indent, true);
        }
    }
