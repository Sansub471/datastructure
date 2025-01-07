#pragma once
// Hard : 42. Trapping Rain Water
// Given n non-negative integers representing an elevation map where the width of each bar is 1, 
// compute how much water it can trap after raining.

#include<vector>
int trap(std::vector<int>& height) {
    const int SIZE = height.size();

    std::vector<int> leftMax(SIZE, 0);
    std::vector<int> rightMax(SIZE, 0);

    //int leftIndex = 0, rightIndex = SIZE - 1;
    int lMax = 0, rMax = 0, trappedWater = 0;

    // calculate left Max and right Max, for each i
    for(int i = 0; i < SIZE; ++i){
        leftMax[i] = lMax;
        lMax = std::max(lMax, height[i]);

        rightMax[SIZE - i - 1] = rMax;
        rMax = std::max(rMax, height[SIZE - i - 1]);
    }

    // calculate trapped water for each i,
    for(int i = 0 ; i < SIZE; ++i){
        int water_i = std::min(leftMax[i], rightMax[i]) - height[i];
        if(water_i > 0) trappedWater += water_i;
    }
    return trappedWater;
}