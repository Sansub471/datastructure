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