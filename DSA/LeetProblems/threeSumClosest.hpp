# pragma once
#include<vector>
#include<algorithm>

int threeSumClosest(std::vector<int>& nums, int target) {
    int gDiff = __INT32_MAX__; // Global minimum difference
    int gSum = 0; // Closest sum
    std::sort(nums.begin(), nums.end()); // Sort input array
    int SIZE = nums.size();

    for (int i = 0; i < SIZE - 2; ++i) {
        if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicates for `nums[i]`

        int left = i + 1, right = SIZE - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            int diff = target - sum;

            // Update closest sum and global difference if the current sum is closer
            if (std::abs(diff) < gDiff) {
                gDiff = std::abs(diff);
                gSum = sum;
            }

            // Move pointers based on the value of `diff`
            if (diff > 0) {
                ++left; // Increase the sum
            } else if (diff < 0) {
                --right; // Decrease the sum
            } else {
                // Exact match found, return immediately
                return sum;
            }
        }
    }

    return gSum; // Return the closest sum
}