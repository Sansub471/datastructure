#pragma once
// 35. Search Insert Position

// Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, 
// return the index where it would be if it were inserted in order.

// You must write an algorithm with O(log n) runtime complexity.
#include<vector>

int searchInsert(std::vector<int>& nums, int target) {
    int start = 0, end = nums.size() - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        if (target < nums[mid]) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return start; // At this point, 'start' is the correct insertion index
}