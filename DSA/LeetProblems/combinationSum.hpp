#pragma once
#include<vector>
#include<algorithm>

void backtrackCombinations(std::vector<int>& candidates, std::vector<std::vector<int>>& combinations, 
                            std::vector<int>& currComb, int remaining, int index){
    if(remaining == 0){
        // valid combination found
        combinations.push_back(currComb);
        return;
    }

    if(remaining < 0){
        // combination invalid
        return;
    }

    for(int i = index; i < candidates.size(); ++i){
        // choose current candidate
        int candidate = candidates[i];
        currComb.push_back(candidate);

        // recur with updated remaining, and i since we can reuse the candidate
        backtrackCombinations(candidates, combinations, currComb, remaining - candidate, i);

        // backtrack by removing the last added candidate
        currComb.pop_back();
    }      
}

std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
    std::vector<std::vector<int>> combinations;
    // 1. sort the candidates to prevent duplicate combination
    //sort(candidates.begin(), candidates.end()); // not necessary as distinct elements are guaranteed.

    // 2. Backtracking and DF search technique
    std::vector<int> currComb;
    backtrackCombinations(candidates, combinations, currComb, target, 0);
    return combinations;
}

// Time complexity : O(2^N)

// Combination Sum II
void backtrack(std::vector<int>& candidates, std::vector<std::vector<int>>& combinations, 
                std::vector<int>& currComb, int remaining, int startIndex){
    if(remaining == 0){
        combinations.push_back(currComb);
        return;
    }

    if(remaining < 0){
        return;
    }

    for(int i = startIndex; i < candidates.size(); ++i){
        int candidate = candidates[i];
        if(i > startIndex && candidates[i - 1] == candidate) continue;
        int remTarget = remaining - candidate;
        //if(remTarget < 0) break; // can replace remaining < 0 check

        currComb.push_back(candidate);
        backtrack(candidates, combinations, currComb, remTarget, i + 1);
        currComb.pop_back();
    }
}

std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
    std::vector<std::vector<int>> combinations;
    std::vector<int> currComb;

    // sort to remove duplicates, candidates are not unique
    sort(candidates.begin(), candidates.end());
    int startIndex = 0;
    backtrack(candidates, combinations, currComb, target, startIndex);
    return combinations;
}

// Generate combinations from given array
// unlike next_permutation, next_combination is not part of the standard C++ library. 
// To generate combinations, you typically need to write a custom function or use techniques 
// involving std::bitset or std::vector for binary representation.

// Custom Approach for Combinations
// Here's a common technique using std::bitset or loop control:

// Use Binary Representation:

// Represent the selection of elements with binary values (0 for not included, 1 for included).
// For example, to generate all combinations of length k from an array, use binary values that have exactly k bits set to 1.
// std::next_permutation on Binary Mask:

// Create a "mask" vector where the last k elements are 1 and the rest are 0.
// Use std::next_permutation on this mask to generate each unique combination.
std::vector<std::vector<int>> generateCombinations(const std::vector<int>& nums, int k) {
    std::vector<std::vector<int>> result;
    int n = nums.size();
    
    // Create a binary mask with `k` 1s at the end for initial combination
    std::vector<int> mask(n, 0);
    std::fill(mask.end() - k, mask.end(), 1);
    
    do {
        std::vector<int> combination;
        for (int i = 0; i < n; ++i) {
            if (mask[i] == 1) {
                combination.push_back(nums[i]);
            }
        }
        result.push_back(combination);
    } while (std::next_permutation(mask.begin(), mask.end()));
    
    return result;
}

// k = number of elements taken
