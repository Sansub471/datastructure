#pragma once
#include<vector>
#include<algorithm>
int majorityElement(std::vector<int>& nums) {
    int n = nums.size();
    std::sort(nums.begin(), nums.end());
    int count = 0, i;
    for(i = 0; i < n; ++i){
        if(i > 0 && nums[i] == nums[i - 1]){
            ++count;
            continue;
        }else{
            if(count > n/2) return nums[i-1];
            count = 1;
        }
    }
    if(count > n/2) return nums[i-1];
    // for compiler
    return -1;
}

// Sorting takes O(NlogN) where as after sorting only O(N) hence sorting time is the time complexity

std::vector<int> majorityElement2(std::vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    std::vector<int> result;
    int count = 0, i;
    for(i = 0; i < n; ++i){
        if(i > 0 && nums[i] == nums[i-1]){
            ++count;
            continue;
        }else{
            if(count > n / 3) result.push_back(nums[i-1]);
            count = 1;
        }
    }
    if(count > n / 3) result.push_back(nums[i-1]);
    return result;
}