#pragma once 
// 209. Minimum Size Subarray Sum
// Given an array of positive integers nums and a positive integer target, return the minimal length of a 
// subarray  whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

// Example 1:

// Input: target = 7, nums = [2,3,1,2,4,3]
// Output: 2
// Explanation: The subarray [4,3] has the minimal length under the problem constraint.
// Example 2:

// Input: target = 4, nums = [1,4,4]
// Output: 1
// Example 3:

// Input: target = 11, nums = [1,1,1,1,1,1,1,1]
// Output: 0

#include<vector>
// Sliding window approach using two pointers.

int minSubArrayLen(int target, std::vector<int>& nums) {
    int tail = 0, head = 0;
    long sum = 0;
    int length = nums.size() + 1; // Max length of the subarray is the array itself
    while(tail < nums.size()){
        if(head < nums.size() && nums[head] >= target) return 1;
        if(sum >= target){
            // shrink window from the left
            while(sum >= target){
                length = std::min(length, head - tail);
                sum -= nums[tail++];
            }
        }else{
            if(head < nums.size()){
                sum += nums[head++];
            }else{
                break;
            }
        }
    }
    return (length == nums.size() + 1) ? 0 : length;
}
//Time :  O(N) 