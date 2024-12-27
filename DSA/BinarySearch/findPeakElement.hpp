#pragma once
// 162. Find Peak Element

// A peak element is an element that is strictly greater than its neighbors.

// Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, 
// return the index to any of the peaks.

// You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a 
// neighbor that is outside the array.

// You must write an algorithm that runs in O(log n) time.

#include<vector>
int findPeakElementLinear(std::vector<int>& nums) {
    if(nums.size() == 1) return 0;
    for(int i = 0; i < nums.size(); ++i){
        if(i == 0){
            if(nums[0] > nums[1]) return 0;
        }else if(i == nums.size() - 1){
            if(nums[i-1] < nums[i]) return i;
        }else{
            if(nums[i] > nums[i-1] && nums[i] > nums[i + 1]) return i;
        }
    }
    return -1; // Fallback, if there is no peak. Testcase ensures ther is a peak
}

// This is a linear approach(O(N)), the required solution must be binary search. O(logN)

// The binary approach is given below:

int findPeakElementBinary(std::vector<int>& nums) {
    if(nums.empty()) return -1;

    int low = 0, high = nums.size() - 1;
    // low <= high will cause out of bound if mid = size() - 1
    while(low < high){
        int mid = low + (high - low) / 2;
        if(nums[mid] > nums[mid + 1]){ // peak is on the left including the mid
            high = mid;
        }else{
            low = mid + 1;
        }
    }
    // loop terminates when low == high
    return low;
}

// Time : O(logN) and Space : O(1)