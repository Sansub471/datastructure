#pragma once
#include<vector>

// 238. Product of Array Except Self
// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums 
// except nums[i].

// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

// You must write an algorithm that runs in O(n) time and without using the division operation.

// For every element i, 
// In prefix array : product of elements before i
// In suffix array : product of elements after i
// product[i] = prefix[i] * suffix[i] combine the two arrays into the product array

std::vector<int> productExceptSelf(std::vector<int>& nums) {
    const int SIZE = nums.size();
    std::vector<int> prefix(SIZE, 1);
    std::vector<int> suffix(SIZE, 1);
    std::vector<int> product(SIZE, 1);

    for(int i = 1; i < SIZE; ++i){
        prefix[i] = prefix[i-1] * nums[i-1];
    }

    for(int i = SIZE - 2; i >= 0; --i){
        suffix[i] = suffix[i+1] * nums[i+1];
    }

    for(int i = 0; i < SIZE; ++i){
        product[i] = prefix[i] * suffix[i];
    }
    return product;
}