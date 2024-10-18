// zig-zag level order traversal 
//left-right, right-left and so on
#include<vector>
#include<queue>
#include<algorithm>

template<typename T>
    std::vector<std::vector<int>> zigzagLevelOrder(T* root) {
        if(root == nullptr) return {{}};
        struct key{
            T* node;
            int level;
        };
        std::queue<key> q;
        key k = {root, 0};
        q.push(k);
        int prevLevel = 0, currentLevel = 0;

        std::vector<int> lnodes;
        std::vector<std::vector<int>> leveledNodes;
        bool direction = true;
        while(!q.empty()){
            k = q.front();
            q.pop();

            T* node = k.node;
            currentLevel = k.level;
            
            if(prevLevel == currentLevel){
                lnodes.push_back(node->data);
            }else{
                if(direction){
                    direction = false;
                }else{
                    std::reverse(lnodes.begin(), lnodes.end());
                    direction = true;
                }
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
        if(!direction){
            std::reverse(lnodes.begin(), lnodes.end());
        }
        leveledNodes.push_back(lnodes);
        return leveledNodes;        
    }

// leetcode improved solution
template<typename T>
    std::vector<std::vector<int>> zigzagLevelOrderLeet(T* root) {
            std::vector<std::vector<int>> leveledNodes; // all levelwise nodes
            if(root == nullptr) return leveledNodes;
            std::queue<T*> q;
            q.push(root);

            bool flag = true; // control direction 
            while(!q.empty()){
                int size = q.size();
                std::vector<int> lvlNodes(size); // nodes of a level, minimum size will be 'size'
                for(int i = 0; i < size; i++){
                    T* node = q.front();
                    q.pop();
                    int index = flag ? i : (size - 1 - i);
                    lvlNodes.at(index) = node->data;
                    if(node->left) q.push(node->left);
                    if(node->right) q.push(node->right);
                }
                flag = !flag; 
                leveledNodes.push_back(lvlNodes);
            }

            return leveledNodes;
        }