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
// Time coplexity for the code added, can you derive yourself?