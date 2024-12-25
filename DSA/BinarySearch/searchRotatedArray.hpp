#pragma once
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