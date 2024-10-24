#pragma once
#include"TreeNode.hpp"
int sumPath(TreeNode* root, int pathSum){
    if(root == nullptr) return 0;
    int sum = pathSum * 10 + root->val;
    if(root->left == nullptr && root->right == nullptr) return sum;
    int leftSum = sumPath(root->left, sum);
    int rightSum = sumPath(root->right, sum);
    return leftSum + rightSum;
}
int sumNumbers(TreeNode* root) {
    return sumPath(root, 0);
}