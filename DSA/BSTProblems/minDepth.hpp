#include<queue>

// Method I : Recursive approach
template<typename T>
    int minDepthRecur(T* root){
        if(root == nullptr) return 0;
        if(root->left == nullptr && root->right == nullptr) return 1;
        int l = __INT_MAX__, r = __INT_MAX__;
        if(root->left) l = minDepthRecur(node->left);
        if(root->right) r = minDepthRecur(node->right);
        return std::min(l, r) + 1;
    }
// Time : O(n)
// Space : O(h)

// Method II : level order traversal approach
template<typename T>
      int minDepth(T* root) {
        if(root == nullptr) return 0;
        struct Key{
            T* node;
            int depth;
        };
        std::queue<Key> Q;
        Key k = {root, 1};
        Q.push(k);
        while(!Q.empty()){
            k = Q.front();
            Q.pop();

            T* node = k.node;
            int depth = k.depth;
            if(node->left == nullptr && node->right == nullptr) return depth;

            if(node->left != nullptr){
                k.node = node->left;
                k.depth = depth + 1;
                Q.push(k);
            }

            if(node->right != nullptr){
                k.node = node->right;
                k.depth = depth + 1;
                Q.push(k);
            }
        }
        return 0;
    }
// Time and Space : O(n)