
// Recursively move to the left and right subtree and at each call decrease the sum by the value of the current node.
// If at any level the current node is a leaf node and the remaining sum is equal to zero then return true.   
template<typename T>
    bool PathSum(T* root, int sum) {
        if (root == NULL) return 0;

        int subSum = sum - root->val;     
        if (subSum == 0 && root->left == nullptr && root->right == nullptr)
            return 1;

        // Otherwise check both subtrees
        bool left = 0, right = 0;
        
        if (root->left)
            left = PathSum(root->left, subSum);
        if (root->right)
            right = PathSum(root->right, subSum);

        return left || right;
    }