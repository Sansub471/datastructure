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
    int tail = 0, head = 0; // Sliding window pointers
    long sum = 0;           // Current window sum
    int minLength = nums.size() + 1; // Initialize to max possible length + 1

    while (tail < nums.size()) {
        // If the current window satisfies the condition
        if (sum >= target) {
            // Shrink the window from the left to minimize the length
            minLength = std::min(minLength, head - tail);
            sum -= nums[tail++];
        } 
        // Expand the window from the right
        else if (head < nums.size()) {
            sum += nums[head++];
        } 
        // If head has reached the end but the sum is still < target, break out
        else {
            break;
        }
    }

    // Return the minimal length, or 0 if no valid subarray exists
    return (minLength == nums.size() + 1) ? 0 : minLength;
}
//Time :  O(N)

// Alternative implementation with for loop
int minSubArrayLenII(int target, std::vector<int>& nums) {
    int head = 0;       
    long sum = 0;           
    int minLength = nums.size() + 1; 
    for (int tail = 0; tail < nums.size(); ++tail) {
        // Expand the window while the sum is less than the target
        while (head < nums.size() && sum < target) {
            sum += nums[head++];
        }
        if (sum >= target) {
            minLength = std::min(minLength, head - tail);
            // Shrink the window by moving the tail
            sum -= nums[tail];
        }else{
            break; // head reached to last but sum < target
        }
    }
    return (minLength == nums.size() + 1) ? 0 : minLength;
}


// Try : O(N logN) complexity