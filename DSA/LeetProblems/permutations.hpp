#pragma once
#include<vector>

void backtrack(std::vector<int>& nums, int startIndex, 
                std::vector<std::vector<int>>& permutations){
    if(startIndex == nums.size()){
        // all pos complete, a permutation complete
        permutations.push_back(nums);
        return;
    }

    for(int i = startIndex; i < nums.size(); ++i){
        // swap to put the i-th element in the current slot(startIndex)
        std::swap(nums[startIndex], nums[i]);

        // recur to fill the next slot
        backtrack(nums, startIndex + 1, permutations);

        // backtrack: swap back to restore the original array
        std::swap(nums[startIndex], nums[i]);
    }
}

std::vector<std::vector<int>> permute(std::vector<int>& nums) {
    std::vector<std::vector<int>> permutations;
    backtrack(nums, 0, permutations);
    return permutations;
}

// Time complexity : O(n!) n! permutations for an array of length n
// Space complexity : O(n) due to the recursion depth and the storage of each permutation.