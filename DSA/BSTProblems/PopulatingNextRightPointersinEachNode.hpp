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
        Node* prevFront = nullptr;
        for(int i = 0; i < SIZE; i++){
            Node* currFront = Q.front();
            currFront->next = prevFront;
            Q.pop();
            if(currFront->right) Q.push(currFront->right);
            if(currFront->left) Q.push(currFront->left);
            prevFront = currFront;
        }
        //prevFront->next = nullptr;
    }
    return root;
}

// Time and Space : O(N), have to traverse every N nodes