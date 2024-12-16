#pragma once
#include<vector>
#include<algorithm>

std::vector<int> targetIndices(std::vector<int>& nums, int target) {
    const int SIZE = nums.size();
    if(SIZE == 0) return {};
    std::vector<int> positions;

    std::sort(nums.begin(), nums.end());
    for(int i = 0 ; i < SIZE; ++i){
        if(nums[i] == target) positions.push_back(i);
    }
    return positions;
}