#pragma once
#include"TreeNode.hpp"
#include<iostream>

int Gmax = INT32_MIN; // global path max tracker, kept privately in a class

int pathSumMax(TreeNode* root){
    if(root == nullptr) return 0;
    // max gain from left and right subtree
    int maxLgain = std::max(0, pathSumMax(root->left));
    int maxRgain = std::max(0, pathSumMax(root->right));

    int maxNodeGain = root->val + std::max(maxLgain, maxRgain);
    int pathSumThroughNode = root->val + maxLgain + maxRgain; // path sum through curr node

    Gmax = std::max(Gmax, pathSumThroughNode);
    return maxNodeGain;
}
int maxPathSum(TreeNode* root) {
    pathSumMax(root);
    return Gmax;
}