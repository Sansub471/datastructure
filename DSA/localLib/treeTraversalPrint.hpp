#ifndef TREE_TRAVERSAL
#define TREE_TRAVERSAL
#include<iostream>
#include<queue>
#include<vector>

namespace Traversal{
template <typename T>
    void preorderDFSHelper(T* root, std::vector<int>& result) {
        if (root == nullptr) return;
        result.push_back(root->data); // just for printing purpose
        preorderDFSHelper(root->left, result);
        preorderDFSHelper(root->right, result);
    }

template <typename T>
    void inorderDFSHelper(T* root, std::vector<int>& result) {
        if (root == nullptr) return;
        inorderDFSHelper(root->left, result);
        result.push_back(root->data); // just for printing purpose
        inorderDFSHelper(root->right, result);
    }

template <typename T>
    void postorderDFSHelper(T* root, std::vector<int>& result) {
        if (root == nullptr) return;
        postorderDFSHelper(root->left, result);
        postorderDFSHelper(root->right, result);
        result.push_back(root->data); // just for printing purpose
    }

// print 1D vector
template <typename T>
    void printVector1D(const std::vector<T>& vec) {
        std::cout << "[";
        for (size_t i = 0; i < vec.size(); ++i) {
            std::cout << vec[i];
            if (i < vec.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]";
    }

template <typename T>
    void preorderDFS(T* root) {
        std::vector<int> result;
        preorderDFSHelper(root, result);
        printVector1D(result);
    }

template <typename T>
    void inorderDFS(T* root) {
        std::vector<int> result;
        inorderDFSHelper(root, result);
        printVector1D(result);
    }

template <typename T>
    void postorderDFS(T* root) {
        std::vector<int> result;
        postorderDFSHelper(root, result);
        printVector1D(result);
    }

// Breadth-first traversal(BFS)
// Level order traversal(left-right)
// The vector element is just for printing, you could simply cout the data there
template<typename T>
    void levelOrderHelper(T* root, std::vector<int>& result){
        if(root == nullptr) return; // empty tree
        std::queue<T*> Q;
        Q.push(root);
        while(!Q.empty()){
            // print front of queue and remove it from queue
            T* node = Q.front();
            //std::cout<< node->data << " ";
            result.push_back(node->data);
            Q.pop();

            // Enqueue left child
            if(node->left != nullptr) Q.push(node->left);

            // Enqueue right child
            if(node->right != nullptr) Q.push(node->right);
        }
    }

template<typename T>
    void levelOrder(T* root){
        std::vector<int> result;
        levelOrderHelper(root, result);
        printVector1D(result);
    }

// Breadth-first traversal(BFS)
// Level order traversal(right-left)
template<typename T>
    void levelOrderR(T* root){
        if(root == nullptr) return; // empty tree
        std::queue<T*> Q;
        Q.push(root);
        while(!Q.empty()){
            // print front of queue and remove it from queue
            T* node = Q.front();
            std::cout<< node->data << " ";
            Q.pop();

            // Enqueue right child
            if(node->right != nullptr) Q.push(node->right);

            // Enqueue left child
            if(node->left != nullptr) Q.push(node->left);
        }
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



// print 2D vector
template <typename T>
    void printVector2D(const std::vector<std::vector<T>>& vec) {
        std::cout << "[";
        for (size_t i = 0; i < vec.size(); ++i) {
            std::cout << "[";
            for (size_t j = 0; j < vec[i].size(); ++j) {
                std::cout << vec[i][j];
                if (j < vec[i].size() - 1) {
                    std::cout << ",";
                }
            }
            std::cout << "]";
            if (i < vec.size() - 1) {
                std::cout << ",";
            }
        }
        std::cout << "]" << std::endl;
    }

// print BST trees, 1 to N
template<typename T>
    void printBST1toN(const std::vector<T*>& trees){
        std::cout<<"[";
        for (int i = 0; i < trees.size(); ++i) {
            preorderDFS(trees[i]);
            if(i != trees.size() - 1) std::cout << ", ";
        }
        std::cout<<"]"<<std::endl;
    }

}
#endif