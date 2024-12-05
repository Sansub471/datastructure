// 26. Remove Duplicates from Sorted Array

#pragma once
#include<vector>
int removeDuplicates(std::vector<int>& nums) {
    const int SIZE = nums.size();
    if(SIZE == 0) return 0;

    int tracker = 1;
    for(int i = 1; i < SIZE; ++i){
        if(nums[i] == nums[i-1]) continue;
        nums[tracker++] = nums[i];
    }
    return tracker;
}