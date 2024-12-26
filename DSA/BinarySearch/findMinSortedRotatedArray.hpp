#pragma once
#include<vector>
// 153. Find Minimum in Sorted Rotated Array
// Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] 
// might become:

// [4,5,6,7,0,1,2] if it was rotated 4 times.
// [0,1,2,4,5,6,7] if it was rotated 7 times.
// Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

// Given the sorted rotated array nums of unique elements, return the minimum element of this array.

// You must write an algorithm that runs in O(log n) time.

int findMinI(std::vector<int>& nums) {
    int low = 0, high = nums.size() - 1;
    while(low < high){
        int mid = low + (high - low) / 2;
        if(nums[mid] > nums[high]){
            low = mid + 1;
        }else{
            high = mid;
        }
    }
    return nums[low];
}

// When there are duplicates in the array
int findMinII(std::vector<int>& nums) {
    int low = 0, high = nums.size() - 1;
    while(low < high){
        int mid = low + (high - low) / 2;
        if(nums[mid] > nums[high]){
            low = mid + 1;
        }else if(nums[mid] < nums[high]){
            high = mid;
        }else{
            high -= 1; // reducing the search space
        }
    }
    return nums[low];
}

// For both case, time complexity : O(logN) Binary search technique.