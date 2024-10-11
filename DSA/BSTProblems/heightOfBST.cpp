// Find the height of a BST, should work for AVL as well as RB Tree.
template<typename T>
    int BSTheight(T* root){
        if(root == nullptr) return -1;
        int leftHeight = BSTheight(root->left);
        int rightHeight = BSTheight(root->right);
        return std::max(leftHeight, rightHeight) + 1;
    }