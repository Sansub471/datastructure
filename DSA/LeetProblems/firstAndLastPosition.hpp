#pragma once
#include<vector>

std::vector<int> searchRange(std::vector<int>& nums, int target) {
    if(nums.empty()) return {-1, -1};
    int low = 0, high = nums.size() - 1;
    while(low <= high){
        int mid = low + (high - low ) / 2;
        if(nums[mid] == target){
            int start = mid, end = mid;
            while(start > 0 && nums[start - 1] == target) --start;
            while(end < nums.size() - 1 && nums[end + 1] == target) ++end;
            return {start, end};
        }

        if(nums[mid] < target){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return {-1, -1};
}

// Binary search technique : Time = O(logN)
// Using binary search find any occurence in the array first and change the position of 
// mid to locate the first occurence by taking backward step(s) while the last position is found 
// by taking forward step(s).
