#pragma once
// The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, 
// if all the permutations of the array are sorted in one container according to their lexicographical order, then the next 
// permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, 
// the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

// For example, the next permutation of arr = [1,2,3] is [1,3,2].
// Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
// While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
// Given an array of integers nums, find the next permutation of nums.

// The replacement must be in place and use only constant extra memory.

#include<vector>
#include<algorithm>

void nextPermutation(std::vector<int>& nums) {
    int n = nums.size();
    int i = n - 2; // 1. i). right most decreasing pair
    while(i >= 0 && nums[i] >= nums[i + 1]){
        i--;
    }

    // ii). no such pair found
    if( i < 0){
        std::reverse(nums.begin(), nums.end());
        return;
    }

    //2. Find smallest element larger than nums[i] in the right
    int j = n - 1;
    while(nums[j] <= nums[i]){
        j--;
    }

    //3. Swap
    std::swap(nums[i], nums[j]);

    // 4. Reverse the suffix, elements after i
    std::reverse(nums.begin() + i + 1, nums.end());
}

// To make it like std::next_permutation
// return type bool and return false if i < 0 and return true at the end
bool next_Permutation(std::vector<int>& nums) {
    int n = nums.size();
    int i = n - 2; // 1. i). right most decreasing pair
    while(i >= 0 && nums[i] >= nums[i + 1]){
        i--;
    }

    // ii). no such pair found
    if( i < 0){
        std::reverse(nums.begin(), nums.end());
        return false;
    }

    //2. Find smallest element larger than nums[i] in the right
    int j = n - 1;
    while(nums[j] <= nums[i]){
        j--;
    }

    //3. Swap
    std::swap(nums[i], nums[j]);

    // 4. Reverse the suffix, elements after i
    std::reverse(nums.begin() + i + 1, nums.end());
    return true;
}