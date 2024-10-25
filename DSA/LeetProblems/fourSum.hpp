#pragma once
#include<vector>
#include<algorithm>
#include<unordered_map>

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
// Time complexity : O(n^3)

// Four sum II : O(n^2)
int fourSumCount(std::vector<int>& nums1, std::vector<int>& nums2, std::vector<int>& nums3, std::vector<int>& nums4) {
    int count = 0;
    std::unordered_map<long, int> sumMap;
    // creating sum map: O(n^2)
    for(int i = 0; i < nums1.size(); ++i){
        for(int j = 0; j < nums2.size(); ++j){
            long sum = nums1[i] + nums2[j];
            sumMap[sum]++; // if key doesn't exist, value initialized zero
        }
    }
    // search for complement sum, O(n^2)
    for(int k = 0; k < nums3.size(); ++k){
        for(int l = 0; l < nums4.size(); ++l){
            int compSum = -(nums3[k] + nums4[l]);
            if(sumMap.find(compSum) != sumMap.end()){
                count += sumMap[compSum];
            }
        }
    }
    return count;
}