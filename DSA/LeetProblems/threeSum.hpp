#pragma once
#include<vector>
#include<algorithm>

std::vector<std::vector<int>> threeSum(std::vector<int>& nums){
    int n = nums.size();
    std::sort(nums.begin(), nums.end()); // O(nlogn)
    std::vector<std::vector<int>> threeSums;
    // two pointer search : O(n)
    for(int i = 0; i < n; ++i){
        if(i > 0 && nums[i] == nums[i - 1]) continue; // don't for same number twice
        int target = -nums[i];
        int left = i + 1;
        int right = n - 1;
        while(left < right){
            int sum = nums[left] + nums[right];
            if(sum == target){
                threeSums.push_back({nums[i], nums[left], nums[right]});
                // skip duplicates for left and right elements
                // don't search for same left and right element again
                while(left < right && nums[left] == nums[left + 1]) ++left;
                while(left < right && nums[right] == nums[right - 1]) --right;

                // move both inward after finding a valid pointer
                ++left; --right;
            }else if(sum < target){
                // to increase sum move to right
                ++left;
            }else{
                // to decrease sum move to left
                --right;
            }
        }
    }
    return threeSums;
    // overall : O(n^2) is optimum
}