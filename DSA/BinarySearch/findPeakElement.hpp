#pragma once
// 162. Find Peak Element

// A peak element is an element that is strictly greater than its neighbors.

// Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, 
// return the index to any of the peaks.

// You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a 
// neighbor that is outside the array.

// You must write an algorithm that runs in O(log n) time.

#include<vector>
int findPeakElementLinear(std::vector<int>& nums) {
    if(nums.size() == 1) return 0;
    for(int i = 0; i < nums.size(); ++i){
        if(i == 0){
            if(nums[0] > nums[1]) return 0;
        }else if(i == nums.size() - 1){
            if(nums[i-1] < nums[i]) return i;
        }else{
            if(nums[i] > nums[i-1] && nums[i] > nums[i + 1]) return i;
        }
    }
    return -1; // Fallback, if there is no peak. Testcase ensures ther is a peak
}

// This is a linear approach(O(N)), the required solution must be binary search. O(logN)

// The binary approach is given below:

int findPeakElementBinary(std::vector<int>& nums) {
    if(nums.empty()) return -1;

    int low = 0, high = nums.size() - 1;
    // low <= high will cause out of bound if mid = size() - 1
    while(low < high){
        int mid = low + (high - low) / 2;
        if(nums[mid] > nums[mid + 1]){ // peak is on the left including the mid
            high = mid;
        }else{
            low = mid + 1;
        }
    }
    // loop terminates when low == high
    return low;
}

// Time : O(logN) and Space : O(1)

// Part II : 
// 1901. Find a Peak Element II

// A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, 
// and bottom.

// Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return 
// the length 2 array [i,j].

// You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.

// You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.

// Guide : You might end up finding a local peak for each row, and just checking the elements to its top and bottom. 
// This approach won't guarantee a global peak. 

// For eg. mat = [[70,50,40,30,20],[100,1,2,3,4]]
// Finding a local peak approach, will find any peak, the second row can have two local peaks 100 and 4
// It doesn't guarantee this local peak will meet the required conditions.

