#pragma once
// 75. Sort Colors

// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, 
// with the colors in the order red, white, and blue.

// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

// You must solve this problem without using the library's sort function.

// Two pointer problem section
#include<vector>

void sortColors(std::vector<int>& nums) {
    int countRED = 0, countWHITE = 0, countBLUE = 0;
    for(auto num : nums){
        if(num == 0){
            ++countRED;
        }else if(num == 1){
            ++countWHITE;
        }else{
            ++countBLUE;
        }
    }
    int index = 0;
    for(int i = 0; i < countRED; ++i) nums[index++] = 0;
    for(int i = 0; i < countWHITE; ++i) nums[index++] = 1;
    for(int i = 0; i < countBLUE; ++i) nums[index++] = 2;
}