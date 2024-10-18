#include<vector>
#include<queue>
template<typename T>
    std::vector<std::vector<int>> levelTraversalArray(T* root){
        if(root == nullptr) return {{}};
        struct key{
            T* node;
            int level;
        };
        std::queue<key> q;
        key k = {root, 0};
        q.push(k);
        std::vector<std::vector<int>> leveledNodes;
        std::vector<int> lnodes;
        int prevLevel = 0;
        int currentLevel = 0;
        while(!q.empty()){
            k = q.front();
            q.pop();

            T* node = k.node;
            currentLevel = k.level;

            if(prevLevel == currentLevel){
                lnodes.push_back(node->data);
            }else{
                leveledNodes.push_back(lnodes);
                lnodes.clear();
                lnodes.push_back(node->data);
            }

            if(node->left != nullptr){
                k.node = node->left;
                k.level = currentLevel + 1;
                q.push(k);
            }

            if(node->right != nullptr){
                k.node = node->right;
                k.level = currentLevel + 1;
                q.push(k);
            }
            prevLevel = currentLevel;
        }
        leveledNodes.push_back(lnodes);
        return leveledNodes;
    }

// Input : Binary Tree or BST or AVL or RB Tree
// Output : [[L0-Array], [L1-Array], ..., [Ln-Array]]
// Time complexity: O(n), just like traversal only 

// Better leetcode solution 
template<typename T>
    std::vector<std::vector<int>> levelOrderTraverse(T* root) {
        std::vector<std::vector<int>> leveledNodes; // nodes of all levels
        if(root == nullptr) return {{}};
        std::queue<T*> q;
        q.push(root);
        std::vector<int> lvlNodes; // nodes of one level
        while(!q.empty()) {
            int n = q.size();
            for(int i = 0; i < n; i++) {
                T* currNode = q.front();
                q.pop();
                lvlNodes.push_back(currNode->data);
                if(currNode->left != nullptr) q.push(currNode->left);
                if(currNode->right != nullptr) q.push(currNode->right);
            }
            leveledNodes.push_back(lvlNodes);
            lvlNodes.clear();
        }
        return leveledNodes;
    }
