#pragma once
#include<vector>
#include<unordered_set>
#include<algorithm>

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

// Permutation with duplicates
void backtrackUnique(std::vector<int>& nums, int startIndex, 
                std::vector<std::vector<int>>& permutations){
    if(startIndex == nums.size()){
        // all pos complete, a permutation complete
        permutations.push_back(nums);
        return;
    }

    std::unordered_set<int> seen; // track elements at the current level

    for(int i = startIndex; i < nums.size(); ++i){
        if(seen.find(nums[i]) != seen.end()) continue;
        seen.insert(nums[i]);

        // swap to put the i-th element in the current slot(startIndex)
        std::swap(nums[startIndex], nums[i]);

        // recur to fill the next slot
        backtrackUnique(nums, startIndex + 1, permutations);

        // backtrack: swap back to restore the original array
        std::swap(nums[startIndex], nums[i]);
    }
}

std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
    std::vector<std::vector<int>> permutations;
    std::sort(nums.begin(), nums.end());
    backtrackUnique(nums, 0, permutations);
    return permutations;
}

// leetcode solution
class Solution {
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        std::vector<std::vector<int>> vec;
        std::sort(nums.begin() , nums.end());
        do{
            vec.push_back(nums);
        }while(next_permutation(nums.begin() , nums.end()));

        return vec;
    }
};

// next_permutation, a standard C++ function that rearranges the elements in the next lexicographical(sorted) order. 
// It starts with the smallest permutation (because nums is sorted) and generates the next unique permutation each time 
// it’s called. Once all unique permutations  have been generated and nums returns to its original sorted order, 
// next_permutation will return false, and the loop ends.