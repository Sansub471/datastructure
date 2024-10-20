#pragma once
// Binary Tree Right Side View
// Given the root of a binary tree, imagine yourself standing on the right side of it, 
// return the values of the nodes you can see ordered from top to bottom.

#include<vector>
#include<queue>

// Tip : Level order traverse(right-left), add the first node on every level into the list
// First node on every level is the rightmost node of that level in right-left traversal
template<typename T>
    std::vector<int> rightSideView(T* root) {
        if(root == nullptr) return {};
        std::vector<int> rightView;
        std::queue<T*> q;
        q.push(root);
        // Add level transition nodes to the rightView
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i < size; i++){
                T* currentNode = q.front();
                q.pop();
                if( i == 0) rightView.push_back(currentNode->data);
                if(currentNode->right != nullptr) q.push(currentNode->right);
                if(currentNode->left  != nullptr) q.push(currentNode->left);
            }
        }
        return rightView;
    }