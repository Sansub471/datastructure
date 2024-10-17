// given a binary tree, find the average of each levels
#include<vector>
#include<queue>

template<typename T>
    std::vector<double> avgOfLevels(T* root){
        if(root == nullptr) return {};
        struct key{
            T* node;
            int level;
        };
        std::queue<key> q;
        key k = {root, 0};
        q.push(k);

        double sumOfLevel = 0, avg=0;
        int levelNodeCount = 0;
        int prevLevel = 0, currentLevel = 0;
        std::vector<double> avgOfLevels;

        while(!q.empty()){
            k = q.front();
            q.pop();

            T* node = k.node;
            currentLevel = k.level;

            if(prevLevel == currentLevel){
                sumOfLevel += node->data;
                levelNodeCount++;
            }else{
                avg = sumOfLevel / levelNodeCount;
                avgOfLevels.push_back(avg);
                sumOfLevel = node->data;
                levelNodeCount = 1;
            }

            if(node->left){
                k.node = node->left;
                k.level = currentLevel + 1;
                q.push(k);
            }

            if(node->right){
                k.node = node->right;
                k.level = currentLevel + 1;
                q.push(k);
            }
            prevLevel = currentLevel;
        }
        avg = sumOfLevel / levelNodeCount;
        avgOfLevels.push_back(avg);
        return avgOfLevels;
    }