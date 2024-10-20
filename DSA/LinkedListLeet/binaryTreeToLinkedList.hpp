// Flatten Binary Tree to Linked List
// Given the root of a binary tree, flatten the tree into a "linked list":
// The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left 
// child pointer is always null.
// The "linked list" should be in the same order as a pre-order traversal of the binary tree.
#pragma once
#include<stack>
#include"../Linked_list/linked_list.hpp"

typedef LinkedList::Node ListNode;

// My Implementation
template<typename T>
    T* flatTree(T* root){
        if(root == nullptr) return nullptr;
        if(root->left == nullptr && root->right == nullptr) return root;

        T* leftTree = flatTree(root->left);
        T* rightTree = flatTree(root->right);
        root->left = nullptr;

        if(leftTree){
            root->right = leftTree;
            while(leftTree->right != nullptr){
                leftTree = leftTree->right;
            }
            leftTree->right = rightTree;
        }else{
            root->right = rightTree;
        }
        return root;
    }

// Can you flatten the tree in-place, with O(1) extra space.

//Reverse a section of a linked list
ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (head == nullptr) return head;
    ListNode* forward = head;
    ListNode* previous = nullptr;
    int count = 1;
    
    // Move forward to the left-th node, track the node before it (previous)
    while (count < left) {
        previous = forward;
        forward = forward->next;
        count++;
    }
    // `previous` now points to the node before the left-th node
    // `forward` now points to the left-th node        
    std::stack<ListNode*> stk;
    
    // Push nodes to the stack from `left` to `right`
    while (count <= right) {
        stk.push(forward);
        forward = forward->next;
        count++;
    }
    
    // Now we need to pop from the stack and reconnect the nodes
    while (!stk.empty()) {
        if (previous != nullptr) {
            previous ->next = stk.top();
            previous  = previous ->next;
        } else {
            head = stk.top(); // If reversing from the head, change the head pointer
            previous = head;
        }
        stk.pop();
    }
    // Reconnect the rest of the list
    previous ->next = forward;
    return head;
}