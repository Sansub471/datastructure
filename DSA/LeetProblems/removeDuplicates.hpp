// 26. Remove Duplicates from Sorted Array

// Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. 
// The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

// Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

// Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums 
// initially. The remaining elements of nums are not important as well as the size of nums.
// Return k.

#pragma once
#include<vector>
int removeDuplicates(std::vector<int>& nums) {
    const int SIZE = nums.size();
    if(SIZE == 0) return 0;

    int tracker = 1;
    for(int i = 1; i < SIZE; ++i){
        if(nums[i] == nums[i-1]) continue;
        nums[tracker++] = nums[i];
    }
    return tracker;
}

// Time : O(N)
// Space : O(1)

// 80. Remove Duplicates from Sorted Array II
// Same concept, at max two repetition allowed.
int removeDuplicatesII(std::vector<int>& nums) {
    if(nums.empty()) return 0;
    
    const int SIZE = nums.size();
    int tracker = 1;
    int count = 0;
    for(int i = 1; i < SIZE; ++i){
        if(nums[i] == nums[i-1]){
            if(count == 0) {
                nums[tracker++] = nums[i]; 
                count++;
            }
            continue;
        }
        count = 0;
        nums[tracker++] = nums[i];
    }
    return tracker;
}