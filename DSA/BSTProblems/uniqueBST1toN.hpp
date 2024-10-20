#pragma once 
#include<vector>

template<typename T>
    // Function to construct all possible binary trees 
    std::vector<T*> getTrees(int start, int end) {
        std::vector<T*> trees;

        // Base case: If start index is greater than end, 
        // return empty tree (nullptr)
        if (start > end) {
            trees.push_back(nullptr);
            return trees;
        }

        // Iterate through all values in the array 
        // and construct left and right subtrees
        for (int i = start; i <= end; ++i) {
            
            // Generate all left subtrees
            std::vector<T*> leftTrees = getTrees<T>(start, i - 1);

            // Generate all right subtrees
            std::vector<T*> rightTrees = getTrees<T>(i + 1, end);

            // Combine each left and right subtree with 
            // the current root
            for (T* left : leftTrees) {
                for (T* right : rightTrees) {
                    
                    // Make i as root
                    T* root = new T(i); 
                    root->left = left;
                    root->right = right;

                    // Add the constructed tree to the list of trees
                    trees.push_back(root);
                }
            }
        }
        return trees;
    }

template<typename T>
    std::vector<T*> uniqueBST1toN(int N){
        return getTrees<T>(1, N);
    }