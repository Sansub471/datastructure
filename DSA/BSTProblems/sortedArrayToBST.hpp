#include<vector>
template<typename T>
    T* sortedArrayToBSTHelper(std::vector<int>& nums, int start, int end){
        if(start > end) return nullptr;
        int mid = start + (end - start) / 2;
        T* node = new T(nums.at(mid));
        node->left  = sortedArrayToBSTHelper<T>(nums, start, mid - 1);
        node->right = sortedArrayToBSTHelper<T>(nums, mid + 1, end);
        return node;
    }

template<typename T>
    T* sortedArrayToBST(std::vector<int>& nums){
        if(nums.empty()) return nullptr;
        int n = nums.size();
        return sortedArrayToBSTHelper<T>(nums, 0, n-1);
    }