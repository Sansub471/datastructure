#pragma once
#include<vector>
// 33. Search in Rotated Sorted Array

// There is an integer array nums sorted in ascending order (with distinct values).

// Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such 
// that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 
// For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, 
// or -1 if it is not in nums.

// You must write an algorithm with O(log n) runtime complexity.

// High-Level Strategy
//     Use binary search with two pointers (low, high).
//     Identify which part of the array is sorted at each step.
//     Narrow the search space based on whether the target is in the sorted or unsorted part.
//     Repeat until the target is found or the search space is exhausted.
//     This approach guarantees O(logn) complexity due to the halving of the search space at each step.

int searchRotatedI(std::vector<int>& nums, int target) {
    if(nums.empty()) return -1;
    int low = 0, high = nums.size() - 1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(nums[mid] == target) return mid;

        // check which part is sorted
        // if left half is sorted
        if(nums[low] <= nums[mid]){
            if(nums[low] <= target && target < nums[mid]){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        // if right half is sorted
        if(nums[mid] <= nums[high]){
            if(nums[mid] < target && target <= nums[high]){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
    }
    return -1;
}

// 81. Search in Rotated Sorted Array II
// The given array can have duplicates, how it affects the search and solution strategy? 

// Key Observations with Duplicates
//     Ambiguity: If nums[low] == nums[mid] == nums[high], it’s unclear where the pivot lies.
//     Handling Equal Values: Increment low or decrement high cautiously to narrow the search space.
//     Worst Case: Time complexity can degrade to O(n) when all elements are the same.

// Modified Strategy for Binary Search
// Standard Cases:
//     If nums[mid] == target, return mid.
//     If the left half (nums[low] to nums[mid]) is sorted and contains the target, search left; otherwise, search right.
//     If the right half (nums[mid] to nums[high]) is sorted and contains the target, search right; otherwise, search left.
// Handle Ambiguity: 
//     When nums[low] == nums[mid] == nums[high], increment low or decrement high.

bool searchRotatedII(std::vector<int>& nums, int target) {
    if(nums.empty()) return false;
    int low = 0, high = nums.size() - 1;
    while(low <= high){
        int mid = low + (high - low) / 2;

        if(nums[low] == target || nums[mid] == target || nums[high] == target) return true;

        // standard case:
        if(nums[low] < nums[mid]){
            if(nums[low] <= target && target < nums[mid]){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }else if(nums[mid] < nums[high]){
            if(nums[mid] < target && target <= nums[high]){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }else{
            // Ambiguity case: nums[low] == nums[mid] == nums[high] or any two equal.
            low = low + 1;
            high = high - 1;
        }
    }
    return false;
}
// Time Complexity:
//     Best Case: O(logn) for standard cases where the array is well-partitioned.
//     Worst Case: O(n) for scenarios with extensive duplicates (e.g., [1, 1, 1, ..., 1]).
// This worst-case degradation is unavoidable due to the nature of ambiguous cases.