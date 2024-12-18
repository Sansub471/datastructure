#pragma once
#include<vector>


int removeElement(std::vector<int>& nums, int val) {
    const int SIZE = nums.size();
    if(SIZE == 0) return 0;

    int left = 0, right = SIZE - 1;
    while(left <= right){
        while(right >= 0 && nums[right] == val) --right;
        if(left > right) break;
        if(nums[left] == val) {
            nums[left] = nums[right];
            --right;
        }
        ++left;
    }
    return left;
}