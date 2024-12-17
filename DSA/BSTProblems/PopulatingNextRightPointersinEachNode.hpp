#pragma once

// 116. Populating Next Right Pointers in Each Node
// You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. 
// The binary tree has the following definition:

// struct Node {
//   int val;
//   Node *left;
//   Node *right;
//   Node *next;
// }
// Populate each next pointer to point to its next right node. If there is no next right node, the next pointer 
// should be set to NULL.

// Initially, all next pointers are set to NULL.

// Definition for a Node.

#include<queue>
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


Node* connect(Node* root) {
    if(root == nullptr) return root;
    std::queue<Node*> Q;
    Q.push(root);
    while(!Q.empty()){
        int SIZE = Q.size();
        Node* prevFront;
        for(int i = 0; i < SIZE; i++){
            Node* currFront = Q.front();
            Q.pop();
            if(i == 0){
                prevFront = currFront;
            }else{
                prevFront->next = currFront;
                prevFront = currFront;
            }
            if(currFront->left) Q.push(currFront->left);
            if(currFront->right) Q.push(currFront->right);
        }
        prevFront->next = nullptr;
    }
    return root;
}

// Time and Space : O(N), have to traverse every N nodes

// While using level order traversal in binary trees, natural order of traversal i.e. left-right is faster than right-left
// The storage of binary tree ans CPU cache are designed that way.