#pragma once
#include<vector>
#include<algorithm>

std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
    int n = nums.size();
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> _4sums;
    for(int i = 0; i < n; ++i){
        if(i > 0 && nums[i] == nums[i - 1]) continue;
        long _3sumTarget = target - nums[i];
        for(int j = i + 1; j < n; ++j){
            if(j > i + 1 && nums[j] == nums[j - 1]) continue;
            long _2sumTarget = _3sumTarget - nums[j];
            // 2 poiter search 
            int left = j + 1;
            int right = n - 1;
            while(left < right){
                long lrSum = nums[left] + nums[right];
                if(lrSum == _2sumTarget){
                    _4sums.push_back({nums[i], nums[j], nums[left], nums[right]});
                    // remove duplicates for left and right 
                    while(left < right && nums[left] == nums[left + 1]) ++left;
                    while(left < right && nums[right] == nums[right - 1]) --right;
                    // move left and right inward
                    ++left;
                    --right;
                }else if(lrSum < _2sumTarget){
                    ++left;
                }else{
                    --right;
                }
            }
        }
    }
    return _4sums;
}