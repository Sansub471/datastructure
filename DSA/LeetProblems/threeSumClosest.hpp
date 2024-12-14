# pragma once
#include<vector>
#include<algorithm>

int threeSumClosest(std::vector<int>& nums, int target) {
    int gDiff = INT_MAX;
    std::sort(nums.begin(), nums.end()); // O(nlogn)
    int SIZE = nums.size();

    // two pointer search : O(n)
    for(int i = 0; i < SIZE; ++i){
        if( i > 0 && nums[i - 1] == nums[i]) continue; // skip same numbers
        int targetComp = - nums[i];
        int left = i + 1, right = SIZE - 1;

        while(left < right){
            int sum = nums[left] + nums[right];
            int lDiff = targetComp - sum;

            if(std::abs(lDiff) < gDiff || lDiff == 0){
                gDiff = std::abs(lDiff);
                // skip duplicates for left and right elements
                // don't search for same left and right element again
                while(left < right && nums[left] == nums[left + 1]) ++left;
                while(left < right && nums[right] == nums[right - 1]) --right;

                // move both inward after valid triplet
                --right;
                ++left;
            }else if(lDiff < 0){
                // decrease the sum to decrease lDiff
                --right;
            }else if(lDiff > 0){
                // increase the sum to decrease lDiff
                ++left;
            }
        }
    }
    return gDiff;
}