// Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. 
// (i.e., from left to right, level by level from leaf to root).

// Trick : Try to reverse the levelTraversalArray.hpp 
// Reverse the 'leveledNodes', time complexity = O(n)
// The traversal itself had O(n) complexity
#include<stack>
#include<queue>
#include<vector>

template<typename T>
    std::vector<std::vector<int>> levelOrderBottom(T* root){
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
        std::stack<std::vector<int>> stk;
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
                stk.push(lnodes);
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
        stk.push(lnodes);

        // empty the stack now
        while(!stk.empty()){
            leveledNodes.push_back(stk.top());
            stk.pop();
        }
        return leveledNodes;
    }

// Time complexity : O(n)
// Space complexity : O(n)

// If you just want the nodes in a array, not level wise, traverse the tree in right-left manner and push 
// each node into the stack and later pop the stak until its empty.

//Hint : left-right : left child goes into the queue first followed by the right child.
// right-left : right child goes into the queue first followed by the left child.  