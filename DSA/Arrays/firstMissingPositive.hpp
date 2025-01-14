#pragma once
// 41. First Missing Positive
// Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.

// You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

// Example 1:

// Input: nums = [1,2,0]
// Output: 3
// Explanation: The numbers in the range [1,2] are all in the array.
// Example 2:

// Input: nums = [3,4,-1,1]
// Output: 2
// Explanation: 1 is in the array but 2 is missing.
// Example 3:

// Input: nums = [7,8,9,11,12]
// Output: 1
// Explanation: The smallest positive integer 1 is missing.
#include<vector>
int firstMissingPositive(std::vector<int>& nums) {
    const int N = nums.size();
    for (int i = 0; i < N; ++i) {
        // Check if nums[i] is within the valid range and not already in the correct position
        while (nums[i] > 0 && nums[i] <= N && nums[i] != nums[nums[i] - 1]) {
            swap(nums[i], nums[nums[i] - 1]);
        }
    }

    // Find the first missing positive
    for (int i = 0; i < N; ++i) {
        if (nums[i] != i + 1) return i + 1;
    }

    return N + 1;
}

// Analysis : Time O(N) and Space O(1)